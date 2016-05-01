/*
Solucion http://acm.tju.edu.cn/toj/showp1414.html
Programador: cams93
*/
#include "templeDune.h"

double ax, bx, cx;
double ay, by, cy;
double ab, ac, bc;
double ca, cb, cc;
double abac, abbc, acbc;
double r, centerx, centery;
double epsilon = 0.001;
double angle[3];
int debug = 0;

int main(int argc, char *argv[]){
	if(argc != 7){
		printf("Wrong usage [x1 y1 x2 y2 x3 y3]\n");
		exit(-1);
	}
	ax = atof(argv[1]);
	ay = atof(argv[2]);
	bx = atof(argv[3]);
	by = atof(argv[4]);
	cx = atof(argv[5]);
	cy = atof(argv[6]);
	findVectors();
	return 0;
}

/* Find the length of the 3 possible sides */
void findVectors(){
	ab = ((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)); 
	ab = sqrt(ab);
	ac = (cx-ax)*(cx-ax) + (cy-ay)*(cy-ay); 
	ac = sqrt(ac);
	bc = (cx-bx)*(cx-bx) + (cy-by)*(cy-by); 
	bc = sqrt(bc);
	abac = (bx-ax)*(cx-ax) + (by-ay)*(cy-ay);
	abbc = (bx-ax)*(cx-bx) + (by-ay)*(cy-by);
	acbc = (cx-ax)*(cx-bx) + (cy-ay)*(cy-by);
	if(debug) printf("ab = %f\n", ab);
	if(debug) printf("ac = %f\n", ac);
	if(debug) printf("bc = %f\n", bc);
	findAngle();
}

/* Find the radius */
void findRadius(double a, double b ,double c){
	double  temp;
	temp = (a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c);
	r = a*b*c/sqrt(temp);
}

/* Find the center of the circle */
void findCenter(){
	double r, t, temp;
	if(ay - bx == 0 || cx - bx == 0){
		centerx = 0;
		centery = 0;
	}
	else{
		r = (ax - by)/(ay - bx);
		t = (cy - by)/(cx - bx);
		if(debug) printf("test %f %f\n", r, t);
		temp = r*t*(cy - ay)+r*(bx + cx)-t*(ax + bx);
		centerx = temp / (2*(r - t));
		temp = centerx - ((ax + bx)/2);
		temp *= (-1/r);
		if(debug) printf("test2 %f\n", temp);
		centery = temp + ((ay + by)/2);
	}
}

/* Find n points */
void findN(){
	int n = 6, v1 = 0, v2 = 0, v3 = 0, i;
	double angle, originalAngle, x, y;
	while(n <= 6){
		angle = 2 * M_PI / n;
		originalAngle = angle;
		for(i = 1; i< (n + 1); i++){
			y = 0 + r * cos(angle);
			x = 0 + r * sin(angle);
			if(abs(x - ax) < epsilon && abs(y - ay) < epsilon){
				v1 = 1;
				if(debug) printf("v1\n");
			}
			if(abs(x - bx) < epsilon && abs(y - by) < epsilon){
				v2 = 1;
				if(debug) printf("v2\n");
			}
			if(abs(x - cx) < epsilon && abs(y - cy) < epsilon){
				v3 = 1;
				if(debug) printf("v3\n");
			}
			angle = originalAngle * (i + 1);
			if(debug) printf("x = %f y = %f\n",x,y );
		}
		if(v1 && v2 && v3){
			if(debug) printf("n = %d\n", n);
			break;
		}
		n++;
	}
}

/* Find angle */
void findAngle(){
	int i, enter = 0;
	angle[1] = calculateAngle(ab, ac, abac);
	angle[2] = calculateAngle(ab, bc, abbc);
	angle[0] = calculateAngle(ac, bc, acbc);
	//qsort(angle,sizeof(angle)/sizeof(angle[0]), sizeof(angle[0]), cmp);
	if(debug) printf("Angles %f %f %f\n", angle[0], angle[1], angle[2]);
	for(i = 0; i < 3; i++){
		if(numberVertices(angle[i])){
			enter = 1;
			break;
		}
	}
	if(enter == 0){
		printf("23\n");
	}
}

/* Calculate angle */
double calculateAngle(double a, double b, double c){
	double angle;
	angle = c/(a*b);
	angle = acos(angle)*180/M_PI;
	if(debug) printf("Angle = %f\n", angle);
	return angle;
}

/* Calculate number of vertices */
int numberVertices(double angle){
	int n;
	double compare;
	n = 360/angle;
	compare = 360.0/angle;
	if(debug) printf("%d %f %f\n", n, compare, n - compare);
	if((compare - n) < epsilon){
		printf("%d\n", n);
		return 1;
	}
	if(debug) printf("Vertices = %d\n", n);
	return 0;
}

int cmp(const void *x, const void *y){
  double xx = *(double*)x, yy = *(double*)y;
  if (xx < yy) return -1;
  if (xx > yy) return  1;
  return 0;
}
