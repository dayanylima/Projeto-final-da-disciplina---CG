#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <cstdlib>

#define VERMELHO 1
#define VERDE 2
#define AMARELO 3
#define WIDTH 1050
#define HEIGHT 700
#define DIA  1
#define NOITE  2
#define LIGADO  1
#define DESLIGADO  0

GLint periodo, luz;
GLfloat c, n, tr, SPEED;
bool farolLigado = false, chovendo = false;
float farolAlpha = 1.0;
int farolPiscando = 0;
float rainY = 60.0; 
// Variáveis
char texto[50];
char t1[50],t2[50],t3[50],t4[50],t5[50],t6[50];

GLfloat win;
GLint view_w, view_h;

void init(void)
{
	luz = VERDE;
    periodo = DIA;
    farolLigado = false;
    chovendo = false;
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(-60, 60, -40, 40, -200, 200);
    
	strcpy(t1, "R -muda a cor do semaforo para vermelho");
	strcpy(t2, "G - muda a cor do semaforo para verde");
	strcpy(t3, "A - muda a cor do semaforo para amarelo");
	strcpy(t4, "L - liga farol de carro");
	strcpy(t5, "D - desliga farol de carro");
	strcpy(t6, "Botao do mouse direito muda periodo e inicia chuva");
	
	win=40.0f;
	strcpy(texto, "(0,0)");
    
}

void DesenhaTexto(char *string)
{  
  glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*0.05));
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++);
glPopMatrix();
}

void MostraTeclas(char *t1, char *t2, char *t3, char *t4, char *t5, char *t6)
{  
  	glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*.20));
        // Exibe caracter a caracter
        while(*t1)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t1++);
        glPopMatrix();
             
  		glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*.25));
        // Exibe caracter a caracter
        while(*t2)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t2++);
        glPopMatrix();
        
        glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*.30));
        // Exibe caracter a caracter
        while(*t3)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t3++);
        glPopMatrix();
        
        glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*.35));
        // Exibe caracter a caracter
        while(*t4)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t4++);
        glPopMatrix();
        
         glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(-win,win-(win*.40));
        // Exibe caracter a caracter
        while(*t5)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t5++);
        glPopMatrix();
        
         glRasterPos2f(-win,win-(win*.45));
        // Exibe caracter a caracter
        while(*t6)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*t6++);
        glPopMatrix();
        
		     
             
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: 
        exit(0);
        glutPostRedisplay();
        break;
    case 'r': 
    case 'R': 
        luz = VERMELHO;
        glutPostRedisplay();
        break;   
    case 'g': 
    case 'G':
    	luz = VERDE;
        glutPostRedisplay();
        break;      
    case 'a': 
    case 'A': 
        luz = AMARELO;
        glutPostRedisplay();
        break;  
	case 'l': 
    case 'L': 
        farolLigado = LIGADO;
        glutPostRedisplay();
        break;	
    case 'd': 
    case 'D': 
        farolLigado = DESLIGADO;
        glutPostRedisplay();
        break;	    
			 
    }
}

void TeclasEspeciais(int key, int x, int y)
{

}

void RodasCarro(int x, int y, int circ)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
  
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++)
    {
        float theta = i * 3.1415926535897932384626433832795 / 180.0;
        float a = circ * cos(theta)+c;
        float b = circ * sin(theta);
        glVertex2f(a, b);
    }
    glEnd();

    glPopMatrix();
}

void RodasOnibus(int x, int y, int circ)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
  
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++)
    {
        float theta = i * 3.1415926535897932384626433832795 / 180.0;
        float a = circ * cos(theta) + c;
        float b = circ * sin(theta);
        glVertex2f(a, b);
    }
    glEnd();

    glPopMatrix();
}

void RodasTrem(int x, int y, int circ)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);
  
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 360; i++)
    {
        float theta = i * 3.1415926535897932384626433832795 / 180.0;
        float a = circ * cos(theta)+tr;
        float b = circ * sin(theta);
        glVertex2f(a, b);
    }
    glEnd();

    glPopMatrix();
}

void circulo(int x, int y, int circ)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    glBegin(GL_TRIANGLE_FAN); 
    glVertex2f(0.0, 0.0); 
    for (int i = 0; i <= 360; i++)
    {
        float theta = i * 3.1415926535897932384626433832795 / 180.0;
        float a = circ * cos(theta);
        float b = circ * sin(theta);

        glVertex2f(a, b);
    }

    glEnd();

    glPopMatrix();
}

void triangulo(float x, float y, float t)
{
    glPushMatrix();
    
    if(periodo== DIA)
	{
	  glColor3f(0.59, 0.29, 0.0);
	}
	else{
	  glColor3f(0.43, 0.21, 0.1);
	}
    
    glTranslatef(x, y, 0.0);
    glScalef(t, t, 0.0);
    glBegin(GL_TRIANGLES); 
    glVertex2f(40.0, 20.0);
    glVertex2f(20.0, 0.0);
    glVertex2f(60.0, 0.0);
    glEnd();

    glPopMatrix();
}

void nuvem(float x, float y, float t)
{
	glPushMatrix();
    glTranslatef(x, y, 0.0);  //Move a nuvem

    if(chovendo == true)
	{
	   //glColor3f(0.44, 0.5, 0.56);
	   glColor3f(0.4, 0.4, 0.4);
	}
	else{
	  glColor3f(1.0, 1.0, 1.0);
	}
    
    // Reduz o tamanho da nuvem
    glScalef(t, t, 0.0);
    circulo(21 + n, 20, 2.0);
    circulo(24 + n, 20, 3.0);
    circulo(28 + n, 20, 3.0);
    circulo(32 + n, 20, 3.0);
    circulo(35 + n, 20, 2.0);
    circulo(25 + n, 22, 3.0);
    circulo(31 + n, 22, 4.0);
	glPopMatrix();   
}


void semaforo(){
	
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	 glVertex2f(52.0 , -25.0);
     glVertex2f(52.0 , -9.0);	
	glEnd();
	
	glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
	 glVertex2f(49.0 , -9.0);
     glVertex2f(55.0 , -9.0);
	 glVertex2f(55.0 , 7.0);
     glVertex2f(49.0 , 7.0);	
     
	glEnd();
	
	if(luz == VERMELHO){	   
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, -6.0, 2.0);
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, -1.0, 2.0);
	   glColor3f(1.0, 0.0, 0.0);
	   circulo(52.0, 4.0, 2.0);
	}
	else
	if(luz == AMARELO){  
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, -6.0, 2.0);
	   glColor3f(1.0, 1.0, 0.0);
	   circulo(52.0, -1.0, 2.0);
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, 4.0, 2.0);
	}
	else
	{	   
	   glColor3f(0.0, 1.0, 0.0);
	   circulo(52.0, -6.0, 2.0);
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, -1.0, 2.0);
	   glColor3f(0.0, 0.0, 0.0);
	   circulo(52.0, 4.0, 2.0);
	}
	
}

void limiteEstrada(){
	glLineWidth(4.0f);
    glBegin(GL_LINES);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(-60.0, -25.0);
      glVertex2f(60.0, -25.0);
    glEnd();
}

void divisaoEstrada(){
	
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(3.0f);
	glLineStipple(3, 0x00FF);
    glBegin(GL_LINES);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(-75.0, -33.0);
      glVertex2f(38.0, -33.0);
    glEnd();
    
    glBegin(GL_LINES);
      glColor3f(1.0, 1.0, 1.0);
      glVertex2f(52.0, -33.0);
      glVertex2f(60.0, -33.0);
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void faixa(){
	
	glLineWidth(8.0f);
	for (int i = -27; i > -41; i -=2 ){
	  glBegin(GL_LINES);
       glColor3f(1.0, 1.0, 1.0);
       glVertex2f(40.0,  i);
       glVertex2f(50.0,  i);
      glEnd();
	}
}
void estrada()
{
    glPushMatrix();
    glColor3f(0.15, 0.15, 0.15);
    glBegin(GL_QUADS);
    glVertex2f(-60.0, -25.0);
    glVertex2f(-60.0, -40.0);
    glVertex2f(60.0, -40.0);
    glVertex2f(60.0, -25.0);
    glEnd();  
    glPopMatrix();
}
void folha(float x, float y) {
    glColor3f(0.0, 0.6, 0.0); 
    glBegin(GL_POLYGON);

    int num_segments = 50;  // Ajustar
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float ovalRadiusX = 1.5;  // Raio horizontal
        float ovalRadiusY = 3.0;  // Raio vertical
        float xOval = x + ovalRadiusX * cos(theta);
        float yOval = y + ovalRadiusY * sin(theta);
        glVertex2f(xOval, yOval);
    }

    glEnd();
}

void folha(float x, float y, float inclinacao) {
    glColor3f(0.0, 0.41, 0.0);
    glBegin(GL_POLYGON);

    int num_segments = 30;  // Ajustar
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float ovalRadiusX = 0.4;  // Raio horizontal
        float ovalRadiusY = 1.0;  // Raio vertical
        float xOval = x + ovalRadiusX * cos(theta);
        float yOval = y + ovalRadiusY * sin(theta);

        //Inclinação
        float xInclinado = (xOval - x) * cos(inclinacao) - (yOval - y) * sin(inclinacao) + x;
        float yInclinado = (xOval - x) * sin(inclinacao) + (yOval - y) * cos(inclinacao) + y;

        glVertex2f(xInclinado, yInclinado);
    }

    glEnd();
}

void flor(float x) {
    // Caule
    glLineWidth(3.0f);
    glColor3f(0.0, 0.41, 0.0);
    glBegin(GL_LINES);
    glVertex2f(15.0 + x, -25.0);
    glVertex2f(15.0 + x, -21.5);
    glEnd();
    
    //Folhas
    folha(15.8 + x, -22.5, 40.0);  // Inclinação 
    folha(14.0 + x, -22.5, 155.0); 
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   
    glPointSize(14.0);
    glColor3f(0.87, 0.19, 0.39);
    glBegin(GL_POINTS);
    glVertex2f(15.5 + x, -19.0);
    glVertex2f(14.5 + x, -19.0);
    glVertex2f(14.0 + x, -20.0);
    glVertex2f(16.1 + x, -20.0);
    glVertex2f(14.5 + x, -21.0);
    glVertex2f(15.6 + x, -21.0);
    glEnd();

    glPointSize(10.0);
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(15.0 + x, -20.0);
    glEnd();
}

void grama()
{
    if(periodo== DIA)
	{
	  glColor3f(0.13, 0.55, 0.13);
	}
	else{
	  glColor3f(0.0, 0.25, 0.0);	
	}
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(-60.0, 1.0);
    glVertex2f(-60.0, -25.0);
    glVertex2f(60.0, -25.0);
    glVertex2f(60.0, 1.0);
    glEnd();
    glPopMatrix();
}

void lagoa(){
	
	int num_segments = 23; 
	if(periodo== DIA)
	{
	  //glColor3f(0.25, 0.41, 0.88);
	  glColor3f(0.0, 0.28, 0.67);
	}
	else{
	  glColor3f(0.07, 0.04, 0.56);	
	}
    glPushMatrix();
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = -50.0 + 30.0 * cos(theta);  
        float y = -10.0 + 5.0 * sin(theta);   
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();

}

void ceu(){
    
    if(periodo== DIA)
	{	
	   if(chovendo == true){
	   	
	   	  glColor3f(0.0, 0.55, 0.55);

	   }
	   else{
	   	  glColor3f(0.53, 0.81, 0.92);
	   }
	}
	else{
	   glColor3f(0.0, 0.0, 0.0);
	}
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex2f(-60.0, 40.0);
    glVertex2f(-60.0, 1.0);
    glVertex2f(60.0, 1.0);
    glVertex2f(60.0, 40.0);
    glEnd();

    glPopMatrix();
}

void carro()
{

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    
   glBegin(GL_POLYGON);
      glColor3f(0.0, 0.0, 0.5);
      glVertex2f(-46.0 + c, -18.0);
      glVertex2f(-49.0 + c, -24.0);
      glVertex2f(-49.0 + c, -29.0);
      glVertex2f(-24.0 + c, -29.0);    
      glVertex2f(-24.0 + c, -24.0);
      glVertex2f(-29.0 + c, -24.0);
      glVertex2f(-34.0 + c, -18.0);
    glEnd();
    

    //JANELA 
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-45.0 + c, -19.0);
    glVertex2f(-47.0 + c, -23.0);
    glVertex2f(-41.0 + c, -23.0);
    glVertex2f(-41.0 + c, -19.0);
    glEnd();
    
    //JANELA 
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-40.0 + c, -19.0);
    glVertex2f(-40.0 + c, -23.0);
    glVertex2f(-32.0 + c, -23.0);
    glVertex2f(-35.0 + c, -19.0);
    glEnd();
    
    //RODAS
    glColor3f(0.0, 0.0, 0.0);
    RodasCarro(-44, -29, 2.6);
    RodasCarro(-29, -29, 2.6);
    glColor3f(0.5, 0.5, 0.5);
    RodasCarro(-44, -29, 1);
    RodasCarro(-29, -29, 1);
    glPopMatrix();
    
    glLineWidth(5.0f);   
    glColor3f(1.0, 1.0, 0.0); 
    glBegin(GL_LINES);
	 glVertex2f(-24.0 + c, -27.0);
     glVertex2f(-24.0 + c, -24.5);	
	glEnd();
	
	//FAROL
    if (farolLigado == LIGADO) {
        //Efeito do farol
        if (rand() % 100 < 5) { 
            farolPiscando = !farolPiscando;
        }

        //transparência
        if (farolPiscando) {
            farolAlpha = 0.3;
        } else {
            farolAlpha = 0.2;
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Cor do farol
        glColor4f(1.0, 0.86, 0.35, farolAlpha);

        glBegin(GL_POLYGON);
        glVertex2f(-24.0 + c, -24.5);
        glVertex2f(-24.0 + c, -27.0);
        glVertex2f(-16.0 + c, -30.0);
        glVertex2f(-16.0 + c, -22.0);
        glEnd();

        glDisable(GL_BLEND);
    }
    
}

void sol(){
	
	glColor3f(1.0, 1.0, 0.0);
	circulo(0.0, 30.0, 3.0);	
}

void lua(){

	glColor3f(0.94, 0.9, 0.55);
	circulo(0.0, 30.0, 4.0);
	glColor3f(0.0, 0.0, 0.0);
	circulo(-2.5, 30.0, 4.0);	
}

void fumaca(float x, float y) {
    glPointSize(4.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 3; i++) {
        float offsetX = static_cast<float>(rand() % 3 - 1);
        float offsetY = static_cast<float>(rand() % 3 - 1);
        glColor4f(0.4, 0.4, 0.4, 0.8);  
        glVertex2f(x + offsetX, y + offsetY);
    }
    glEnd();
}

void trem(){
	
	float r, g , b;
	
	if(periodo== DIA)
	{
	  r = 0.0; g = 0.0; b = 0.0;
	}
	else{
	   r = 0.8; g = 0.8; b = 0.0;
	}
	
	//TRILHOS
	glLineWidth(2.0f);
	 
	glColor3f(0.0, 0.0, 0.0); 
    glBegin(GL_LINES);
	 glVertex2f(-60.0, 0.0);
     glVertex2f(60.0, 0.0);	
	glEnd();
	
	glBegin(GL_LINES);
	 glVertex2f(-60.0, -2.0);
     glVertex2f(60.0, -2.0);	
	glEnd();
	
	glColor3f(0.59, 0.29, 0.0);
    for (int i = -62; i < 130; i += 3) {
        glBegin(GL_LINES);
         glVertex2f(-62.0 + i, -2.0);
         glVertex2f(-59.0 + i, 0.0);
        glEnd();
    }
    
    //CHAMINÉ  
    glLineWidth(5.0f);
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_LINES);
         glVertex2f(-60.5 + tr, 2.0);
         glVertex2f(-60.5 + tr, 4.0);
    glEnd();
    fumaca(-60.5 + tr, 6.0);
    
    //CABINE   
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-70.0 + tr, 5.0);
    glVertex2f(-70.0 + tr, -1.0);
    glVertex2f(-59.0 + tr, -1.0);
    glVertex2f(-59.0 + tr, 2.0);
    glVertex2f(-62.0 + tr, 2.0);
    glVertex2f(-62.0 + tr, 5.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-63.0 + tr, 4.0);
    glVertex2f(-63.0 + tr, 2.0);
    glVertex2f(-65.5 + tr, 2.0);
    glVertex2f(-65.5 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-66.5 + tr, 4.0);
    glVertex2f(-66.5 + tr, 2.0);
    glVertex2f(-69.0 + tr, 2.0);
    glVertex2f(-69.0 + tr, 4.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    RodasTrem(-63.0, -1.0, 1.0);
    RodasTrem(-68.0, -1.0, 1.0);
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(8.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POINTS);
    glVertex2f(-63.0 + tr, -1.0);
    glVertex2f(-68.0 + tr, -1.0);
    glEnd();
    
    //Conexão de vagão
    glLineWidth(6.0f);
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_LINES);
	glVertex2f(-70.0 + tr, 0.0);
    glVertex2f(-72.0 + tr, 0.0);	
	glEnd();
	
    //Vagão 1  
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-82.0 + tr, 5.0);
    glVertex2f(-82.0 + tr, -1.0);
    glVertex2f(-72.0 + tr, -1.0);
    glVertex2f(-72.0 + tr, 5.0);
    glEnd();
    
    //janela
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-73.0 + tr, 4.0);
    glVertex2f(-73.0 + tr, 2.0);
    glVertex2f(-75.0 + tr, 2.0);
    glVertex2f(-75.0 + tr, 4.0);
    glEnd();
    
     //janela
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-76.0 + tr, 4.0);
    glVertex2f(-76.0 + tr, 2.0);
    glVertex2f(-78.0 + tr, 2.0);
    glVertex2f(-78.0 + tr, 4.0);
    glEnd();
    
     //janela
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-79.0 + tr, 4.0);
    glVertex2f(-79.0 + tr, 2.0);
    glVertex2f(-81.0 + tr, 2.0);
    glVertex2f(-81.0 + tr, 4.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    RodasTrem(-74.0, -1.0, 1.0);
    RodasTrem(-80.0, -1.0, 1.0);
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(8.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POINTS);
    glVertex2f(-74.0 + tr, -1.0);
    glVertex2f(-80.0 + tr, -1.0);
    glEnd();
    
    //Conexão de vagão
    glLineWidth(6.0f);
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_LINES);
	glVertex2f(-82.0 + tr, 0.0);
    glVertex2f(-94.0 + tr, 0.0);	
	glEnd();
	   
    //Vagão 2 
    glBegin(GL_POLYGON);
     glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-94.0 + tr, 5.0);
    glVertex2f(-94.0 + tr, -1.0);
    glVertex2f(-84.0 + tr, -1.0);
    glVertex2f(-84.0 + tr, 5.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-85.0 + tr, 4.0);
    glVertex2f(-85.0 + tr, 2.0);
    glVertex2f(-87.0 + tr, 2.0);
    glVertex2f(-87.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-88.0 + tr, 4.0);
    glVertex2f(-88.0 + tr, 2.0);
    glVertex2f(-90.0 + tr, 2.0);
    glVertex2f(-90.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-91.0 + tr, 4.0);
    glVertex2f(-91.0 + tr, 2.0);
    glVertex2f(-93.0 + tr, 2.0);
    glVertex2f(-93.0 + tr, 4.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    RodasTrem(-92.0, -1.0, 1.0);
    RodasTrem(-86.0, -1.0, 1.0);
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(8.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POINTS);
    glVertex2f(-92.0 + tr, -1.0);
    glVertex2f(-86.0 + tr, -1.0);
    glEnd();
    
     //Conexão de vagão
    glLineWidth(6.0f);
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_LINES);
	glVertex2f(-94.0 + tr, 0.0);
    glVertex2f(-106.0 + tr, 0.0);	
	glEnd();
    
     //Vagão 3
    glBegin(GL_POLYGON);
     glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-106.0 + tr, 5.0);
    glVertex2f(-106.0 + tr, -1.0);
    glVertex2f(-96.0 + tr, -1.0);
    glVertex2f(-96.0 + tr, 5.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-97.0 + tr, 4.0);
    glVertex2f(-97.0 + tr, 2.0);
    glVertex2f(-99.0 + tr, 2.0);
    glVertex2f(-99.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-100.0 + tr, 4.0);
    glVertex2f(-100.0 + tr, 2.0);
    glVertex2f(-102.0 + tr, 2.0);
    glVertex2f(-102.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-103.0 + tr, 4.0);
    glVertex2f(-103.0 + tr, 2.0);
    glVertex2f(-105.0 + tr, 2.0);
    glVertex2f(-105.0 + tr, 4.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    RodasTrem(-104.0, -1.0, 1.0);
    RodasTrem(-98.0, -1.0, 1.0);
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(8.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POINTS);
    glVertex2f(-104.0 + tr, -1.0);
    glVertex2f(-98.0 + tr, -1.0);
    glEnd();
    
     //Conexão de vagão
    glLineWidth(6.0f);
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_LINES);
	glVertex2f(-106.0 + tr, 0.0);
    glVertex2f(-118.0 + tr, 0.0);	
	glEnd();
    
    //Vagão 4
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-108.0 + tr, 5.0);
    glVertex2f(-108.0 + tr, -1.0);
    glVertex2f(-118.0 + tr, -1.0);
    glVertex2f(-118.0 + tr, 5.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-109.0 + tr, 4.0);
    glVertex2f(-109.0 + tr, 2.0);
    glVertex2f(-111.0 + tr, 2.0);
    glVertex2f(-111.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-112.0 + tr, 4.0);
    glVertex2f(-112.0 + tr, 2.0);
    glVertex2f(-114.0 + tr, 2.0);
    glVertex2f(-114.0 + tr, 4.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(-115.0 + tr, 4.0);
    glVertex2f(-115.0 + tr, 2.0);
    glVertex2f(-117.0 + tr, 2.0);
    glVertex2f(-117.0 + tr, 4.0);
    glEnd();
    
    glColor3f(0.0, 0.0, 0.0);
    RodasTrem(-110.0, -1.0, 1.0);
    RodasTrem(-116.0, -1.0, 1.0);
    
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(8.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POINTS);
    glVertex2f(-110.0 + tr, -1.0);
    glVertex2f(-116.0 + tr, -1.0);
    glEnd();
    	
}

void arvore(){	
	
	glColor3f(0.43, 0.21, 0.1);
	glLineWidth(14.0f);
	glBegin(GL_LINES);
	 glVertex2f(-6.0 , -12.0);
     glVertex2f(-6.0 , -4.0);	
	glEnd();
	
	if(periodo== DIA)
	{
	  glColor3f(0.0, 1.0, 0.0);
	}
	else{
	  glColor3f(0.13, 0.55, 0.13);	
	}
	circulo(-8.0, -2.0, 3.0);
	circulo(-4.0, -2.0, 3.0);
	circulo(-7.0, 2.0, 3.0);
	circulo(-5.0, 2.0, 3.0);
	circulo(-6.0, 5.0, 2.0);
	
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(10.0);
    glColor3f(1.0, 0.5, 0.0);
    if(periodo== DIA)
	{
	   glColor3f(1.0, 0.5, 0.0);
	}
	else{
	  glColor3f(0.8, 0.3, 0.0);	
	}
    glBegin(GL_POINTS);
      glVertex2f(-3.0, -2.0);
      glVertex2f(-7.0, 0.0);
      glVertex2f(-4.0, 2.5);
      glVertex2f(-8.0, 3.0);
      glVertex2f(-6.0, 5.0);
      glVertex2f(-9.0, -3.0);
    glEnd();
		
}

void pinheiro(float x){
	
	glPushMatrix();
    glLineWidth(4.5f);
    glColor3f(0.33, 0.13, 0.10);
    glBegin(GL_LINES);
      glVertex2f(-44.5 + x, 1.0);
      glVertex2f(-44.5 + x, 3.0);
    glEnd();
    
    if(periodo== DIA)
	{
	  glColor3f(0.2, 0.8, 0.2);
	}
	else{
	  glColor3f(0.13, 0.4, 0.13);	
	}
    glBegin(GL_TRIANGLES); 
    glVertex2f(-44.5 + x, 5.0);
    glVertex2f(-46.5 + x, 3.0);
    glVertex2f(-42.5 + x, 3.0);
    glEnd();
    
    glBegin(GL_TRIANGLES); 
    glVertex2f(-44.5 + x, 6.0);
    glVertex2f(-46.0 + x, 4.3);
    glVertex2f(-43.0 + x, 4.3);
    glEnd();
    
    glBegin(GL_TRIANGLES); 
    glVertex2f(-44.5 + x, 7.0);
    glVertex2f(-45.6 + x, 5.5);
    glVertex2f(-43.4 + x, 5.5);
    glEnd();
    
    glPopMatrix();
}

void estrela(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);  //Move a estrela
    glColor3f(1.0, 1.0, 1.0);

    //tamanho da estrela
    glScalef(0.02, 0.02, 0.0);
    
    glBegin(GL_POLYGON);
    glVertex2f(0.0, -10.0);
    glVertex2f(30.0, -30.0);
    glVertex2f(10.0, -5.0);
    glVertex2f(30.0, 15.0);
    glVertex2f(5.0, 5.0);
    glVertex2f(0.0, 30.0);
    glVertex2f(-5.0, 5.0);
    glVertex2f(-30.0, 15.0);
    glVertex2f(-10.0, -5.0);
    glVertex2f(-30.0, -30.0);
    glEnd();

    glPopMatrix();
}


void casa(){
	  
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.0, 0.13);
    glVertex2f(-42.5, 15.0);
    glVertex2f(-55.0, 3.0);
    glVertex2f(-30.0, 3.0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 1.0, 0.0);
    glVertex2f(-42.5, 15.0);
    glVertex2f(-30.0, 3.0);
    glVertex2f(-25.0, 10.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.28, 0.24, 0.55);
    glVertex2f(-55.0, 3.0);
    glVertex2f(-55.0, -15.0);
    glVertex2f(-30.0, -15.0);
    glVertex2f(-30.0, 3.0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.28, 0.24, 0.2);
    glVertex2f(-30.0, 3.0);
    glVertex2f(-30.0, -15.0);
    glVertex2f(-25.0, -7.0);
    glVertex2f(-25.0, 10.0);
    glEnd();
}


void moinho(){
	
	glLineWidth(6.0f);
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_LINES);
	glVertex2f(-45.0 , 1.0);
    glVertex2f(-45.0 , 10.0);	
	glEnd();
	
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_POLYGON);
	glVertex2f(-45.0 , 18.0);
    glVertex2f(-46.0 , 13.0);
	glVertex2f(-45.0 , 10.0);
	glVertex2f(-44.0 , 13.0);	
	glEnd();
    
    glPopMatrix();
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_POLYGON);
	glVertex2f(-45.0 , 10.0);
    glVertex2f(-48.0 , 11.0);
	glVertex2f(-53.0 , 10.0);
	glVertex2f(-48.0 , 9.0);	
	glEnd();
	
	glColor3f(0.3, 0.3, 0.3); 
    glBegin(GL_POLYGON);
	glVertex2f(-45.0 , 10.0);
    glVertex2f(-42.0 , 9.0);
	glVertex2f(-37.0 , 10.0);
	glVertex2f(-42.0 , 11.0);	
	glEnd();
	
}

void chuva() {
    int num_drops = 1000;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLineWidth(2.0);
    glColor4f(0.6, 0.7, 0.8, 0.8); 

    glBegin(GL_LINES);
    for (int i = 0; i < num_drops; i ++) {
        float x = static_cast<float>(rand() % 200 - 60);
        float y = rainY - static_cast<float>(rand() % 200);

        glVertex2f(x, y);
        glVertex2f(x, y - 1.5);  // Comprimento da gota de chuva
    }
    glEnd();
}

void CenaDia(){
    
    if(chovendo == true){
	    grama();
	    ceu();
	    lagoa();
	    flor(20);
	    flor(-70);
	    triangulo(0.0, 1.0, 0.7);
	    triangulo(10.0, 1.0, 1.0);
	    pinheiro(-14.0);
	    pinheiro(-8.0);
	    pinheiro(-2.0);
	    pinheiro(4.0);
	    pinheiro(90.0);
	    pinheiro(84.0);
	    pinheiro(78.0);
	    trem();
	    estrada();
	    semaforo();
	    limiteEstrada();
	    divisaoEstrada();
	    faixa();
	    nuvem(5.0, 10.0, 0.89); 
		nuvem(-65.0, 5.0, 1.0); 
	    nuvem(-25.0, 24.0, 0.6);
	    nuvem(35.0, 24.0, 0.6);
	    nuvem(60.0, 10.0, 0.7);
	    nuvem(-70.0, 24.0, 0.6);
	    nuvem(-120.0, 3.0, 0.99);
	    nuvem(-25.0, 3.0, 0.99);
	     nuvem(-80.0, 5.0, 0.8);
	    arvore();
	    carro();
	    chuva();
	
	}
    else{
    	
		grama();
	    ceu();
	    lagoa();
	    flor(20);
	    flor(-70);
	    triangulo(0.0, 1.0, 0.7);
	    triangulo(10.0, 1.0, 1.0);
	    pinheiro(-14.0);
	    pinheiro(-8.0);
	    pinheiro(-2.0);
	    pinheiro(4.0);
	    pinheiro(90.0);
	    pinheiro(84.0);
	    pinheiro(78.0);
	    trem();
	    estrada();
	    semaforo();
	    limiteEstrada();
	    divisaoEstrada();
	    faixa();
	    sol();
	    nuvem(5.0, 10.0, 0.8); 
		nuvem(-65.0, 5.0, 1.0); 
	    nuvem(-25.0, 28.0, 0.4);
	    nuvem(35.0, 25.0, 0.5);
	    nuvem(60.0, 10.0, 0.7);
	    nuvem(-70.0, 27.0, 0.4);
	    nuvem(-120.0, 5.0, 0.9);
	    arvore();
	    carro();
    }
}

void CenaNoite(){
	
	 if(chovendo == true){
	    
	    grama();
	    ceu();
	    lagoa();
	    flor(20);
	    flor(-70);
	    triangulo(10.0, 1.0, 0.5);
	    triangulo(15.0, 1.0, 0.8);
	    pinheiro(-14.0);
	    pinheiro(-8.0);
	    pinheiro(-2.0);
	    pinheiro(4.0);
	    pinheiro(90.0);
	    pinheiro(84.0);
	    pinheiro(78.0);
	    trem();
	    estrada();
	    semaforo();
	    limiteEstrada();
	    divisaoEstrada(); 
	    faixa();
	    lua();
	    nuvem(5.0, 10.0, 0.89); 
		nuvem(-65.0, 5.0, 1.0); 
	    nuvem(-25.0, 24.0, 0.6);
	    nuvem(35.0, 24.0, 0.6);
	    nuvem(60.0, 10.0, 0.7);
	    nuvem(-70.0, 24.0, 0.6);
	    nuvem(-120.0, 3.0, 0.99);
	    nuvem(-25.0, 3.0, 0.99);
	    nuvem(-80.0, 5.0, 0.8);
	    arvore(); 
	    carro();
	    chuva();
	 }
	 else{
	
	    grama();
	    ceu();
	    lagoa();
	    flor(20);
	    flor(-70);
	    triangulo(10.0, 1.0, 0.5);
	    triangulo(15.0, 1.0, 0.8);
	    pinheiro(-14.0);
	    pinheiro(-8.0);
	    pinheiro(-2.0);
	    pinheiro(4.0);
	    pinheiro(90.0);
	    pinheiro(84.0);
	    pinheiro(78.0);
	    trem();
	    estrada();
	    semaforo();
	    limiteEstrada();
	    divisaoEstrada(); 
	    faixa();
	    lua();
	    estrela(-30.0, 30.0);
	    estrela(-20.0, 25.0);
	    estrela(-25.0, 20.0);
	    estrela(-40.0, 20.0);
	    estrela(-25.0, 20.0);
	    estrela(-55.0, 32.0);
	    estrela(-50.0, 38.0);
	    estrela(-45.0, 27.0);
	    estrela(15.0, 32.0);
	    estrela(20.0, 28.0);
	    estrela(25.0, 35.0);
	    estrela(30.0, 28.0);
	    estrela(27.0, 20.0);
	    estrela(40.0, 28.0);
	    estrela(45.0, 25.0);
	    estrela(55.0, 35.0);
	    estrela(38.0, 37.0);
	    estrela(-55.0, 20.0);
	    estrela(55.0, 20.0);
	    estrela(-35.0, 37.0);
	    estrela(-15.0, 34.0);
	    estrela(0.0, 20.0);
	    estrela(-13.0, 22.0);
	    estrela(13.0, 22.0);
	    arvore(); 
	    carro();
    }
}

void animacaoChuva(int value) {
	
    rainY -= 1.0;  //Controla a descida da chuva
    glutPostRedisplay();
    
}

void movimentacao(){
	 
	   
    if (c > 120) {
        c = -100.0;
    }
    
    if(luz == VERMELHO && (c<65) && (c>60)){
    	SPEED = 0;
    	   	
	}
	
	if(luz ==  VERDE){
    	SPEED = 0.09;
	}
	
	if(luz ==  AMARELO){
    	SPEED = 0.06;
	}
	
	n += 0.003;  
    tr+= 0.08;
    c+=SPEED; 
	
	
	if (n > 150) {
        n = -150.0;
    }
    
    if (tr > 200) {
        tr = -200.0;
    }
    glutPostRedisplay();  
}

void display(void)
{
    
   glClear(GL_COLOR_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);

    switch (periodo)
    {
        case DIA:
            CenaDia();
           break;
        case NOITE:
           CenaNoite();
            break;  	  
    }
    
    glColor3f(0.0f, 0.0f, 0.0f);
    
    if(periodo == NOITE){
     glColor3f(1.0f, 1.0f, 1.0f);
   }
   else{
   	 glColor3f(0.0f, 0.0f, 0.0f);
   }
    DesenhaTexto(texto);
     MostraTeclas(t1, t2, t3, t4, t5, t6);
    glutSwapBuffers();
    
}

void MenuPeriodo(int op){
	
	switch (op)
    {
    case 0:
        periodo = DIA;
         glutPostRedisplay();
        break;
    case 1:
        periodo = NOITE;
         glutPostRedisplay();
        break; 
    }
    glutPostRedisplay();
	
}

void MenuChuva(int op){
	
	switch (op)
    {
    case 0:
        chovendo = true;
         glutPostRedisplay();
        break;
    case 1:
        chovendo = false;
         glutPostRedisplay();
        break; 
    }
    glutPostRedisplay();
	
}

void CriaMenu()
{
    int menu, submenu1, submenu2, submenu3;

    submenu1 = glutCreateMenu(MenuPeriodo);
    glutAddMenuEntry("Dia", 0);
    glutAddMenuEntry("Noite", 1);
    
    submenu2 = glutCreateMenu(MenuChuva);
    glutAddMenuEntry("Iniciar ", 0);
    glutAddMenuEntry("Parar", 1);

    menu = glutCreateMenu(0);
    glutAddSubMenu("Período", submenu1);
    glutAddSubMenu("Chuva", submenu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN)
            CriaMenu();

    glutPostRedisplay();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;                  

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
}

void MoveMouse(int x, int y)
{
     sprintf(texto, "(%d,%d)", x, y);
     glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE  | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Projeto Final");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(movimentacao);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(TeclasEspeciais);
    glutMouseFunc(GerenciaMouse);
    glutPassiveMotionFunc(MoveMouse); 
    glutTimerFunc(50, animacaoChuva, 0);
    glutMainLoop();
    return 0;
}
