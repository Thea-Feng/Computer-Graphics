#include "transforms.h"

#include "CGL/matrix3x3.h"
#include "CGL/vector2D.h"
#include "CGL/vector3D.h"

namespace CGL {

Vector2D operator*(const Matrix3x3 &m, const Vector2D &v) {
	Vector3D mv = m * Vector3D(v.x, v.y, 1);
	return Vector2D(mv.x / mv.z, mv.y / mv.z);
}

Matrix3x3 translate(float dx, float dy) {
	// Part 3: Fill this in.
	Matrix3x3 m;
	m = Matrix3x3(1, 0, dx,  
				0, 1, dy, 
				0,0,1);  

	return m;
}

Matrix3x3 scale(float sx, float sy) {
	// Part 3: Fill this in.
	Matrix3x3 m;

	m = Matrix3x3(sx, 0, 0,  
				0, sy, 0, 
				0,0,1);  

	return m;
}

// The input argument is in degrees counterclockwise
Matrix3x3 rotate(float deg) {
	// Part 3: Fill this in.
	Matrix3x3 m;
	float s = sin(deg*PI/180), c = cos(deg*PI/180);
	m = Matrix3x3(c, -s, 0,  
				s, c, 0, 
				0,0,1);  

	return m;
}

}
