#ifndef __CALCS__
#define __CALCS__

//extern float vieworg[3];
//extern float viewangles[3];
extern float FOV;
extern int m_iCenterX, m_iCenterY;

int __fastcall CalcScreen(const float *origin, float *vecScreen);
void inline RotateAxes(float *Vector, float* Angles, float* NewVector);
void inline RotateAxisX(float *Vector, float gamma, float* NewVector);
void inline RotateAxisY(float *Vector, float beta, float* NewVector);
void inline VectorToAngle(float *Vector, float* Angle);
void inline AngleToVector(float *Angle, float* Vector);
float AngleOfVectors(float* Vector1, float*Vector2);
float VectorLength(float* Vector);

#endif