//#include "MyMath.h"
//#include <cmath>
//#include <stdlib.h>
//#include <time.h>
//
//Matrix4 Identity()
//{
//	return {
//		1, 0, 0, 0,
//		0, 1, 0, 0,
//		0, 0, 1, 0,
//		0, 0, 0, 1,
//	};
//}
//
//Matrix4 MultMatrix4(const Matrix4& mat1, const Matrix4& mat2) {
//
//	Matrix4 m;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			for (int k = 0; k < 4; k++) {
//				m.m[i][j] += mat1.m[i][k] * mat2.m[k][j];
//			}
//		}
//	}
//
//	return m;
//}
//
//Matrix4 Scaling(const Matrix4& mat, const Vector3& scale) {
//	Matrix4 matScale;
//	matScale.m[0][0] = scale.x;
//	matScale.m[1][1] = scale.y;
//	matScale.m[2][2] = scale.z;
//	matScale.m[3][3] = 1.0;
//
//	return MultMatrix4(mat, matScale);
//}
//
//Matrix4 RotationX(const Matrix4& mat, const float rota) {
//	Matrix4 matRota = {
//		1, 0, 0, 0,
//		0, (float)cos(rota), (float)sin(rota), 0,
//		0, (float)-sin(rota), (float)cos(rota), 0,
//		0, 0, 0, 1
//	};
//
//	return MultMatrix4(mat, matRota);
//}
//Matrix4 RotationY(const Matrix4& mat, const float rota) {
//	Matrix4 matRota = {
//		(float)cos(rota), 0, (float)-sin(rota), 0,
//		0, 1, 0, 0,
//		(float)sin(rota), 0, (float)cos(rota),  0,
//		0, 0, 0, 1
//	};
//
//	return MultMatrix4(mat, matRota);
//}
//Matrix4 RotationZ(const Matrix4& mat, const float rota) {
//	Matrix4 matRota = {
//		(float)cos(rota), (float)sin(rota), 0, 0,
//		(float)-sin(rota), (float)cos(rota), 0, 0,
//		0, 0, 1, 0,
//		0, 0, 0, 1
//	};
//
//	return MultMatrix4(mat, matRota);
//}
//
//Matrix4 Rotation(const Matrix4& mat, const Vector3& rota) {
//	Matrix4 m = mat;
//	m = RotationZ(m, rota.z);
//	m = RotationX(m, rota.x);
//	m = RotationY(m, rota.y);
//	return m;
//}
//
//Matrix4 Moving(const Matrix4& mat, const Vector3& move) {
//	Matrix4 matMove = {
//		1, 0, 0, 0,
//		0, 1, 0, 0,
//		0, 0, 1, 0,
//		move.x, move.y, move.z, 1
//	};
//
//	return MultMatrix4(mat, matMove);
//}
//
//void Affine(WorldTransform& wt) {
//	wt.matWorld_ = Identity();
//	wt.matWorld_ = Scaling(wt.matWorld_, wt.scale_);
//	wt.matWorld_ = Rotation(wt.matWorld_, wt.rotation_);
//	wt.matWorld_ = Moving(wt.matWorld_, wt.translation_);
//}
//
//void Srand() { srand(time(NULL)); }
//
//int GetRand(const int start, const int end)
//{
//	int adjust = 1;
//	if (start > end) { adjust = -1; }
//	int div = end - start;
//	if (div > 0) div++;
//	if (div < 0) div--;
//	if (div == 0) return end;
//
//	return adjust * ((rand() % div) + start);
//}
//
//float GetRandF(const float start, const float end, const int place)
//{
//	const int p = static_cast<int>(powf(10, place));
//	const int s = static_cast<int>(start * p);
//	const int e = static_cast<int>(end * p);
//	float result = static_cast<float>(GetRand(s, e)) / p;
//	return result;
//}