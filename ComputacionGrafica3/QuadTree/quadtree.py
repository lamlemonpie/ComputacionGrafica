import cv2 as cv
import numpy as np
import sys

from skimage.color import rgb2lab, deltaE_cie76

#Dibuja un rectangulo en img binarizada
def drawRectangle(p1,p2):
    cv.rectangle(img, tuple(p1),tuple(p2),(0,0,0),1)

def count_similarities(segment):
    if segment.size == 0: return True
    lab_segment     = segment
    pivot_pixel     = lab_segment[0,0]
    for i in lab_segment:
        for j in i:
            if deltaE_cie76(pivot_pixel, j) > 8: return False
    return True
    

#QuadTree Node:     
# Dibujamos un rectangulo cuando se crea
class QNode:
    #   Puntos del cuadrante
    #   p1: izquierda - arriba
    #   p2: derecha - abajo
    def __init__(self,p1,p2):
        self.p1 = p1
        self.p2 = p2
        self.color = 0
        self.hijos = [None] * 4
        self.setColor()
        drawRectangle(self.p1,self.p2)

    #Asigmanos un color entre -1 (gris), 0 (negro) y 1 (blanco) al nodo
    def setColor(self):
        #Contamos todos los no ceros dentro de un cuadrante entre p1 y p2
        similarity = count_similarities(lab_img[ self.p1[1] : self.p2[1] , self.p1[0] : self.p2[0] ])
        self.simi  = similarity
        if(similarity): 
            self.color = 1     #Si todos los pixeles son similars
        else: 
            self.color = -1    #Si hay menos no ceros que ceros

    
    #Calculamos puntos auxiliares para dividir un cuadrante
    #y se crean nodos hijos
    def dividir(self):
        #Centro del cuadrante
        centro = self.p1 + (self.p2 - self.p1)//2
        #Puntos NSEO (Arriba - Abajo, Izquierda - Derecha)
        arriba = np.array([ centro[0] , self.p1[1] ])
        abajo  = np.array([ centro[0] , self.p2[1] ])
        izquierda = np.array([ self.p1[0] , centro[1] ])
        derecha   = np.array([ self.p2[0] , centro[1] ])

        #Creamos nodos hijos con puntos NSEO  
        self.hijos[0] = QNode(self.p1,centro)
        self.hijos[1] = QNode(arriba,derecha)
        self.hijos[2] = QNode(centro,self.p2)
        self.hijos[3] = QNode(izquierda,abajo)


    #Dividimos un cuadrante hasta que su tamaño sea 1 pixel
    #si el color del cuadrante es blanco o negro no se divide
    def deepDivide(self):
        #Tamaño del cuadrante
        if np.array_equal(self.p2-self.p1,(1,1)): 
            return
        #Si el color es gris se divide
        if(self.color == -1): 
            self.dividir()

        #Visualización en tiempo real
        if(realTime):
            cv.imshow(archivo,img)
            cv.waitKey(1)

        if self.hijos == [None] * 4: 
            return
        # Por cada hijo de color gris (-1), se divide
        for i in self.hijos:
            if i.color == -1:
                i.deepDivide()

#QuadTree Class
class QTree:    
    def __init__(self): 
        self.imagen = img
        #The root node is on all the picture
        self.root = QNode(np.array((0,0)), np.array(img.shape[1::-1]))
        #Mostrar imagen binarizada
        cv.imshow(archivo,img)
        #Pedir tecla para continuar
        print("Presione cualquier tecla para comenzar\n")
        cv.waitKey(0)
        #Ejecutando deepDivide
        print("Creando QuadTree...\n")
        self.root.deepDivide()
        #Luego de deepDivide
        cv.imshow(archivo,img)
        print("Presione cuaquier tecla para terminar\n")
        #Guardado de imagen
        cv.imwrite(archivo.split(".")[0]+"Quad.jpg",img)
        cv.waitKey(0)
        cv.destroyAllWindows()

if __name__== "__main__":
    #Para ejecutar en tiempo real
    realTime = int(sys.argv[2])
    #Imagen pasada como argumento
    archivo = sys.argv[1]
    #Mostrando imagen
    img     = cv.imread(archivo)
    #Convirtiendo imagen de rgb a lab
    lab_img = rgb2lab(img)
    #Creando QuadTree
    arbol = QTree()