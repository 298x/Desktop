#include <stdio.h>
#include "GL/glew.h"
#include "GL/glut.h"
#include "glm/vec3.hpp"
using namespace glm;

// Указатель VBO на буфер вершин
GLuint VBO;

void RenderSceneCB() {
	// Очистка буфера кадра
	glClear(GL_COLOR_BUFFER_BIT);

	// координаты вершин, исп. в буфере, рассм. как атрибут вершины с индексом 0
	glEnableVertexAttribArray(0);

	// Обратно привязываем наш буфер, приготавливая его для отрисовки
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Говорим конвейеру, как воспринимать данные внутри буфера
	// 0-индекс атрибута, 3-кол-во компонентов, GL_FLOAT-тип данных компонентов
	// GL_FALSE - не нормализовать атрибуты, 0-число байтов м-у 2 экз. атрибута
	// 0-смещение в структуре, которую получит конвейер
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Вызываем функцию отрисовки
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// Отключение атрибутов вершины
	glDisableVertexAttribArray(0);

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
	
	// Инициализация glew и проверка на ошибки
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error : '%s'\n", glewGetErrorString(res));
	}

	// Инициализация точек
	vec3 Vertices[3];
	// Задаём вершины треугольника
	Vertices[0] = vec3(-1.0f, -1.0f, 0.0f);
	Vertices[1] = vec3(1.0f, -1.0f, 0.0f);
	Vertices[2] = vec3(0.0f, 1.0f, 0.0f);

	// Генерация объектов
	glGenBuffers(1, &VBO);

	// Цель использованиея буферов - хранит массив вершин
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Наполнение объекта нужными данными
	// GL_STATIC_DRAW - флаг, обозначающий исп. паттернов для этих данных
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// Передача контроля GLUTу
	glutMainLoop();



	return 0;
}