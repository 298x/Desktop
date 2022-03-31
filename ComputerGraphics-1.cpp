#include <stdio.h>
#include <conio.h>
#include "GL/glut.h"


void RenderSceneCB() {
	// Очистка буфера кадра
	glClear(GL_COLOR_BUFFER_BIT);
	// Сменя буфера фона на буфер кадра
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	// Инициализация GLUT
	glutInit(&argc, argv);

	// Включение двойной буферизации и буфера цвета
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Размер окна
	glutInitWindowSize(500, 500);
	// Положение окна
	glutInitWindowPosition(100, 100);
	// Создание окна 
	glutCreateWindow("Window");

	// Общение с оконной системой
	// Вызов функции отображения на экран
	glutDisplayFunc(RenderSceneCB);

	// Установка цвета, которой будет использоваться
	// во время очистки буфера кадра
	glClearColor(0.4f, 0.0f, 0.0f, 0.0f);

	// Передача контроля GLUTу
	glutMainLoop();

	return 0;
}