#include <GL/glut.h>
#include <stdio.h> 
#include <malloc.h> 

const double eps = 1e-2;

int size = 80;
int s = 640, t = 480;
int hsize = size / 2;
double sqrt = size/2* 1.73205; //0.8660
double red=0.1, green=0.1, blue=0.1;

int m = 2, n = 2, q = 2, k = 2, o = 2, p = 2,  r = 2;

double  sx1 = 0,  sy1 = 80,
		sx2 = 0,  sy2 = 0,
		sx3 = 80, sy3 = 0,
		sx4 = 80, sy4 = 80;


double	tx1, ty1,
		tx2, ty2,
		tx3, ty3;
int a;

int lv = 1;

bool isEqual(double a, double b) {
	return (a - b >= -eps) && (a - b <= eps);
}


GLuint  textura_id;
struct textura_struct
{
	int W;
	int H;
	unsigned char *Image;
}get_textura;

int LoadTexture(char *FileName)
{
	FILE *F;
	/* Открываем файл */
	if ((F = fopen(FileName, "rb")) == NULL)
		return 0;
	/*Перемещаемся в bmp-файле на нужную позицию, и считываем ширину и длинну */
	fseek(F, 18, SEEK_SET);
	fread(&(get_textura.W), 2, 1, F);
	fseek(F, 2, SEEK_CUR);
	fread(&(get_textura.H), 2, 1, F);

	/* Выделяем память под изображение.*/
	if ((get_textura.Image = (unsigned char *)malloc(sizeof(unsigned char) * 3 * get_textura.W * get_textura.H)) == NULL)
	{
		fclose(F);
		return 0;
	}
	/* Считываем изображение в память по 3 бита, то бишь RGB для каждого пикселя */
	fseek(F, 30, SEEK_CUR);
	fread(get_textura.Image, 3, get_textura.W * get_textura.H, F);

	glGenTextures(1, &textura_id);
	glBindTexture(GL_TEXTURE_2D, textura_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, get_textura.W, get_textura.H, GL_RGB, GL_UNSIGNED_BYTE, get_textura.Image);
	free(get_textura.Image);
	fclose(F);

	return 1;
}

void win() {
	
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // если вернуть строчку то фигура 
	//перестанет перемещаться после победы
	/* Вывод изображения в окне */
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textura_id);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex2d(0, 0);// 0 0 // 0 480 // 640, 480
	glTexCoord2d(1, 0); glVertex2d(640, 0);// 640 0 // 0 0 // 0, 480
	glTexCoord2d(1, 1); glVertex2d(640, 240);// 640 480 // 640 0 // 0, 0
	glTexCoord2d(0, 1); glVertex2d(0, 240);// 0 480 // 640 480 // 640, 0
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void tr1(){
	if (m == 1)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(218.564, 80);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(298.564, 80);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(258.564, 149.282);
		glEnd();
	}

	if		((isEqual(tx1,218.564)    && isEqual (ty1 , 80)		 && isEqual (tx2 , 298.564) && isEqual (ty2 , 80)		&& isEqual (tx3 , 258.564) && isEqual (ty3 , 149.282) ||
			(isEqual (tx2 , 218.564)  && isEqual (ty2 , 80)		 && isEqual (tx3 , 298.564) && isEqual (ty3 , 149.282)  && isEqual (tx1 , 258.564) && isEqual(ty1 , 80)) ||
			(isEqual (tx3 , 218.564)  && isEqual (ty3 , 149.282) && isEqual (tx1 , 298.564) && isEqual (ty1 , 80)		&& isEqual (tx2 , 258.564) && isEqual (ty2 , 80))))

	{
		m = 0;

	}
}
void tr2(){
	if (n == 1)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0.5, 0.5, 1.0);
		glVertex2f(109.282, 189.282);
		glColor3f(0.5, 0.5, 1.0);
		glVertex2f(189.282, 189.282);
		glColor3f(0.5, 0.5, 1.0);
		glVertex2f(149.282, 258.564);
		glEnd();
	}

	if ((isEqual(tx1, 109.282) && isEqual(ty1, 189.282) && isEqual(tx2, 189.282) && isEqual(ty2, 189.282) && isEqual(tx3, 149.282) && isEqual(ty3, 258.564) ||
		(isEqual(tx2, 109.282) && isEqual(ty2, 189.282) && isEqual(tx3, 189.282) && isEqual(ty3, 258.564) && isEqual(tx1, 149.282) && isEqual(ty1, 189.282)) ||
		(isEqual(tx3, 109.282) && isEqual(ty3, 189.282) && isEqual(tx1, 189.282) && isEqual(ty1, 189.282) && isEqual(tx2, 149.282) && isEqual(ty2, 189.282))))

	{
		n = 0;

	}
}
void tr3() {
	if (q == 1)
	{
		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(109.282, 407.846);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(29.282, 407.846);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(69.282, 338.564);
		glEnd();
	}

	if ((isEqual(tx1, 109.282) && isEqual(ty1, 407.846) && isEqual(tx2, 29.282) && isEqual(ty2, 407.846) && isEqual(tx3, 69.282) && isEqual(ty3, 338.564) ||
		(isEqual(tx2, 109.282) && isEqual(ty2, 407.846) && isEqual(tx3, 29.282) && isEqual(ty3, 407.846) && isEqual(tx1, 69.282) && isEqual(ty1, 338.564)) ||
		(isEqual(tx3, 109.282) && isEqual(ty3, 407.846) && isEqual(tx1, 29.282) && isEqual(ty1, 407.846) && isEqual(tx2, 69.282) && isEqual(ty2, 338.564))))

	{
		q = 0;

	}
}

void sq1() {
	if (k == 1) // purple
	{
		glBegin(GL_QUADS);

		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(298.564, 298.564);		//left up

		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(298.564, 218.564);		//left down

		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(378.564, 218.564);		//right down

		glColor3f(1.0, 0.0, 1.0);
		glVertex2f(378.564, 298.564);		//right up

		glEnd();
	}
	//
	if (isEqual(sx1, 298.564) && isEqual(sy1, 298.564) && (isEqual(sx3, 378.564) && isEqual(sy3, 218.564)))
	{
		k = 0;
	}
}
/*void sq2() {
	if (l == 0)
	{
		glBegin(GL_QUADS);

		glColor3f(0.095, 0.095, 0.095);
		glVertex2f(458.564, 80);		//left up

		glColor3f(0.095, 0.095, 0.095);
		glVertex2f(498.564, 10.718);		//left down

		glColor3f(0.095, 0.095, 0.095);
		glVertex2f(567.846, 50.718);		//right down

		glColor3f(0.095, 0.095, 0.095);
		glVertex2f(527.846, 120);		//right up

		glEnd();
	}

	if (isEqual(sx1, 458.564) && isEqual(sy1, 80) && isEqual(sx3, 567.846) && isEqual(sy3, 50.718))
	{
		l = 1;
	}
}*/
void sq3() {
	if (o == 1) // green
	{
		glBegin(GL_QUADS);

		glColor3f(0, 1, 0);
		glVertex2f(437.128, 80);		//left up

		glColor3f(0, 1, 0);
		glVertex2f(437.128, 0);		//left down

		glColor3f(0, 1, 0);
		glVertex2f(517.128, 0);		//right down

		glColor3f(0, 1, 0);
		glVertex2f(517.128, 80);		//right up

		glEnd();
	}

	if (isEqual(sx1, 437.128) && isEqual(sy1, 80) && (isEqual(sx3, 517.128) && isEqual(sy3, 0)))
	{
		o = 0;
	}
}
void sq4() {
	if (p == 1) //red
	{
		glBegin(GL_QUADS);

		glColor3f(1, 0, 0);
		glVertex2f(437.128, 378.564);		//left up

		glColor3f(1, 0, 0);
		glVertex2f(397.128, 309.282);		//left down

		glColor3f(1, 0, 0);
		glVertex2f(466.41, 269.282);		//right down

		glColor3f(1, 0, 0);
		glVertex2f(506.41, 338.564);		//right up

		glEnd();
	}

	if (isEqual(sx1, 437.128) && isEqual(sy1, 378.564) && isEqual(sx3, 466.41) && isEqual(sy3, 269.282))
	{
		p = 0;
	}
}

void F2()
{
	lv = 2;
	sx1 = 0; sy1 = size;
	sx2 = 0; sy2 = 0,
		sx3 = size; sy3 = 0;
	sx4 = size; sy4 = size;
	tx1 = 0;
	ty1 = 0;
	tx2 = 0;
	ty2 = 0;
	tx3 = 0;
	ty3 = 0;
	a = 2;

	n = 1;
	m = 1;
	q = 1;

	k = 0;
	o = 0;
	p = 0;
	red = 0.1, green = 0.1, blue = 0.1;


}
void F3()
{
	lv = 1;
	sx1 = 0; sy1 = size;
	sx2 = 0; sy2 = 0,
		sx3 = size; sy3 = 0;
	sx4 = size; sy4 = size;
	tx1 = 0;
	ty1 = 0;
	tx2 = 0;
	ty2 = 0;
	tx3 = 0;
	ty3 = 0;
	a = 2;

	n = 0;
	m = 0;
	q = 0;


	k = 1;
	o = 1;
	p = 1;

	red = 0.1, green = 0.1, blue = 0.1;
}
void F4()
{
	lv = 3;
	sx1 = 0; sy1 = size;
	sx2 = 0; sy2 = 0,
		sx3 = size; sy3 = 0;
	sx4 = size; sy4 = size;
	tx1 = 0;
	ty1 = 0;
	tx2 = 0;
	ty2 = 0;
	tx3 = 0;
	ty3 = 0;
	a = 2;

	n = 1;
	m = 1;
	q = 1;

	k = 1;
	o = 1;
	p = 1;
	red = 0.1, green = 0.1, blue = 0.1;


}



void sq_move(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP://tr_up();

		tx1 = sx1;
		ty1 = sy1;

		tx2 = sx4;
		ty2 = sy4;

		tx3 = tx1 + hsize;
		ty3 = ty1 + sqrt;
		//tr_up_move(key, x, y);
		a = 3;
		break;

	case GLUT_KEY_LEFT://tr_left();

		tx1 = sx2;
		ty1 = sy2;

		tx2 = sx1;
		ty2 = sy1;

		tx3 = tx2 - sqrt;
		ty3 = ty2 - hsize;
		//tr_left_move(key, x, y);
		a = 7;
		break;

	case GLUT_KEY_DOWN://tr_down();

		tx1 = sx3;
		ty1 = sy3;

		tx2 = sx2;
		ty2 = sy2;

		tx3 = tx2 + hsize;
		ty3 = ty1 - sqrt;
		//tr_down_move(key, x, y);
		a = 5;

		break;

	case GLUT_KEY_RIGHT://tr_right();

		tx1 = sx4;
		ty1 = sy4;

		tx2 = sx3;
		ty2 = sy3;

		tx3 = tx1 + sqrt;
		ty3 = ty1 - hsize;
		//tr_right_move(key, x, y);
		a = 9;
		break;
	}

}
//2
void sq_right_move(int key, int x, int y)
{

	switch (key)
	{
	case GLUT_KEY_UP:

		tx3 = sx4;
		ty3 = sy4;

		tx2 = sx1;
		ty2 = sy1;

		tx1 = sx1;
		ty1 = sy1 + size;
		//tr_right_move(key, x, y);
		a = 9;
		break;
	case GLUT_KEY_LEFT:

		tx3 = sx1;
		ty3 = sy1;

		tx2 = sx2;
		ty2 = sy2;

		tx1 = sx2 - size;
		ty1 = sy2;
		//tr_up_move(key, x, y);
		a = 3;
		break;
	case GLUT_KEY_DOWN:

		tx3 = sx2;
		ty3 = sy2;

		tx2 = sx3;
		ty2 = sy3;

		tx1 = sx3;
		ty1 = sy3 - size;
		//tr_left_move(key, x, y);
		a = 7;
		break;
	case GLUT_KEY_RIGHT:

		tx3 = sx3;
		ty3 = sy3;

		tx2 = sx4;
		ty2 = sy4;

		tx1 = sx4 + size;
		ty1 = sy4;
		//tr_down_move(key, x, y);
		a = 5;
		break;
	}
}
//4
void sq_left_move(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP:

		tx1 = sx4;
		ty1 = sy4;

		tx3 = sx1;
		ty3 = sy1;

		tx2 = sx4;
		ty2 = sy4 + size;
		//tr_right_move(key, x, y);
		a = 7;
		break;

	case GLUT_KEY_LEFT:

		tx1 = sx1;
		ty1 = sy1;

		tx3 = sx2;
		ty3 = sy2;

		tx2 = sx1 - size;
		ty2 = sy1;
		//tr_up_move(key, x, y);
		a = 5;
		break;

	case GLUT_KEY_DOWN:

		tx1 = sx2;
		ty1 = sy2;

		tx3 = sx3;
		ty3 = sy3;

		tx2 = sx2;
		ty2 = sy2 - size;
		//tr_left_move(key, x, y);
		a = 9;
		break;

	case GLUT_KEY_RIGHT:

		tx1 = sx3;
		ty1 = sy3;

		tx3 = sx4;
		ty3 = sy4;

		tx2 = sx3 + size;
		ty2 = sy3;
		//tr_down_move(key, x, y);
		a = 3;
		break;
	}
}
//6

void tr_up_move(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:

		sx4 = tx3;
		sy4 = ty3;

		sx3 = tx1;
		sy3 = ty1;

		sx2 = sx3 - sqrt;
		sy2 = sy3 + hsize;

		sx1 = sx4 - sqrt;
		sy1 = sy4 + hsize;
		//sq_left_move(key, x, y);
		a = 6;
		break;

	case GLUT_KEY_DOWN:

		sx1 = tx1;
		sy1 = ty1;

		sx4 = tx2;
		sy4 = ty2;

		sx3 = sx4;
		sy3 = sy4 - size;

		sx2 = sx1;
		sy2 = sy1 - size;
		//sq_move(key, x, y);
		a = 2;
		break;

	case GLUT_KEY_RIGHT:

		sx1 = tx3;
		sy1 = ty3;

		sx2 = tx2;
		sy2 = ty2;

		sx4 = sx1 + sqrt;
		sy4 = sy1 + hsize;

		sx3 = sx2 + sqrt;
		sy3 = sy2 + hsize;
		//sq_right_move(key, x, y);
		a = 4;
		break;
	}
}
//3
void tr_down_move(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_LEFT:

		sx4 = tx2;
		sy4 = ty2;

		sx3 = tx3;
		sy3 = ty3;

		sx2 = sx3 - sqrt;
		sy2 = sy3 - hsize;

		sx1 = sx4 - sqrt;
		sy1 = sy4 - hsize;
		//sq_right_move(key, x, y);
		a = 4;
		break;

	case GLUT_KEY_UP:

		sx2 = tx2;
		sy2 = ty2;

		sx3 = tx1;
		sy3 = ty1;

		sx1 = sx2;
		sy1 = sy2 + size;

		sx4 = sx3;
		sy4 = sy3 + size;
		//sq_move(key, x, y);
		a = 2;
		break;

	case GLUT_KEY_RIGHT:

		sx1 = tx1;
		sy1 = ty1;

		sx2 = tx3;
		sy2 = ty3;

		sx4 = sx1 + sqrt;
		sy4 = sy1 - hsize;

		sx3 = sx2 + sqrt;
		sy3 = sy2 - hsize;
		//sq_left_move(key, x, y);
		a = 6;
		break;
	}

}
//5
void tr_left_move(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP:

		sx3 = tx2;
		sy3 = ty2;

		sx2 = tx3;
		sy2 = ty3;

		sx1 = sx2 - hsize;
		sy1 = sy2 + sqrt;

		sx4 = sx3 - hsize;
		sy4 = sy3 + sqrt;
		//sq_right_move(key, x, y);
		a = 4;
		break;
	case GLUT_KEY_DOWN:

		sx1 = tx3;
		sy1 = ty3;

		sx4 = tx1;
		sy4 = ty1;

		sx2 = sx1 - hsize;
		sy2 = sy1 - sqrt;

		sx3 = sx4 - hsize;
		sy3 = sy4 - sqrt;
		//sq_left_move(key, x, y);
		a = 6;
		break;
	case GLUT_KEY_RIGHT:

		sx1 = tx2;
		sy1 = ty2;

		sx2 = tx1;
		sy2 = ty1;

		sx3 = sx2 + size;
		sy3 = sy2;

		sx4 = sx1 + size;
		sy4 = sy1;
		a = 2;
		//sq_move(key, x, y);
		break;
	}
}
//7
void tr_right_move(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_UP:

		sx2 = tx1;
		sy2 = ty1;

		sx3 = tx3;
		sy3 = ty3;

		sx1 = sx2 + hsize;
		sy1 = sy2 + sqrt;

		sx4 = sx3 + hsize;
		sy4 = sy3 + sqrt;
		//sq_left_move(key, x, y);
		a = 6;
		break;
	case GLUT_KEY_DOWN:

		sx4 = tx3;
		sy4 = ty3;

		sx1 = tx2;
		sy1 = ty2;

		sx3 = sx4 + hsize;
		sy3 = sy4 - sqrt;

		sx2 = sx1 + hsize;
		sy2 = sy1 - sqrt;
		//sq_right_move(key, x, y);
		a = 4;
		break;
	case GLUT_KEY_LEFT:

		sx4 = tx1;
		sy4 = ty1;

		sx3 = tx2;
		sy3 = ty2;

		sx2 = sx3 - size;
		sy2 = sy3;

		sx1 = sx4 - size;
		sy1 = sy4;
		//sq_move(key, x, y);
		a = 2;
		break;
	}
}
//9



void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glutReshapeWindow(640, 480);


}
void display()
{

		//Фон
	{
		glBegin(GL_QUADS);

		glColor3f(red, green, blue);
		glVertex2f(0, t);		//left up

		glColor3f(red, green, blue);
		glVertex2f(0, 0);		//left down

		glColor3f(red, green, blue);
		glVertex2f(s, 0);		//right down

		glColor3f(red, green, blue);
		glVertex2f(s, t);		//right up

		glEnd();
	}
		
	if(a == 2 || a == 4 || a == 6 ){
	glBegin(GL_QUADS);

		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(sx1, sy1);		//left up 298.564,298.564
	
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(sx2, sy2);		//left down 298.564, 218.564
	
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(sx3, sy3);		//right down 378.564, 218.564
	
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(sx4, sy4);		//right up 378.564, 298.564

	glEnd();
	}
	//square
	else   //if(a == 3 || a == 5 || a == 7 || a == 9  )
	{
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(tx1, ty1);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(tx2, ty2);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(tx3, ty3);
	glEnd(); 
	} 
	//triangle
	
		tr1();
		tr2();
		tr3();
		sq1();
		//sq2();
		sq3();
		sq4();

	//Условия победы
	if (lv == 2 && m == 0 && n == 0 && q == 0) {
		win();
		red = 0;
		green = 0.2;
		blue = 0;

	}
	if (lv == 1 && k == 0 && o == 0 && p == 0) {
		win();
		red = 0;
		green = 0.2;
		blue = 0;

	}
	if (lv == 3 && k == 0 && o == 0 && p == 0 && m == 0 && n == 0 && q == 0) {
		win();
		red = 0;
		green = 0.2;
		blue = 0;

	}
	



	//выход за поле
	if (sx1 <= 0 && sx4 <= 0 ||
		sx2 >= s && sx3 >= s ||
		sy1 >= t && sy2 >= t ||
		sy3 <= 0 && sy4 <= 0 ||

		tx1 <= 0 && tx2 <= 0 && tx3 <= 0 ||
		tx1 >= s && tx2 >= s && tx3 >= s ||
		ty1 <= 0 && ty2 <= 0 && ty3 <= 0 ||
		ty1 >= t && ty2 >= t && ty3 >= t
		) {
		a = 2;
		sx1 = 0; sy1 = size;
		sx2 = 0; sy2 = 0,
		sx3 = size; sy3 = 0;
		sx4 = size; sy4 = size;
		
	}
	//Обновление экрана
	glutPostRedisplay();
	glutSwapBuffers();
	
}
void move(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F2:  //Restart level
		
		F2();
			break;
	case GLUT_KEY_F3:  //Restart level
		
		F3();
		break;
	case GLUT_KEY_F4:  //Restart level

		F4();
		break;
	}

	switch (a)
	{
	case 2 :sq_move(key, x, y); break;
	case 4 :sq_right_move(key, x, y); break;
	case 6 :sq_left_move(key,x,y); break;

	case 3 :tr_up_move(key,x,y); break;
	case 5 :tr_down_move(key,x,y); break;
	case 7 :tr_left_move(key,x,y); break;
	case 9 :tr_right_move(key,x,y); break;
		
	}
glutPostRedisplay();
}
 
int main(int argc, char*argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	
	glutInitWindowSize(s, t);
	glutCreateWindow("Geometry Maze");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(move);

	LoadTexture((char *)"Win_24bit.bmp"); //загружет картинку

	glutMainLoop();

	return 0;
}
