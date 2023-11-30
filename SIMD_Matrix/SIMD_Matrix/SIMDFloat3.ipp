inline SIMDFloat3::SIMDFloat3() : m(_mm_setzero_ps())
{

}

inline SIMDFloat3::SIMDFloat3(NothingInit)
{
}

inline SIMDFloat3::SIMDFloat3(float _x, float _y, float _z) : m(_mm_set_ps(0, _z, _y, _x))
{
}

inline SIMDFloat3::SIMDFloat3(const float* e) : m(_mm_loadu_ps(e))
{
}

inline VECTOR_CALL SIMDFloat3::SIMDFloat3(const __m128 e) : m(e)
{
}

inline  SIMDFloat3 VECTOR_CALL SIMDFloat3::operator+(const SIMDFloat3 v) const
{
	return SIMDFloat3(_mm_add_ps(m, v.m));
}

inline SIMDFloat3& VECTOR_CALL SIMDFloat3::operator+=(const SIMDFloat3 v)
{
	*this = SIMDFloat3(_mm_add_ps(m, v.m)); ;
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator+() const
{
	return *this;
}

inline SIMDFloat3 VECTOR_CALL SIMDFloat3::operator-(const SIMDFloat3 v) const
{
	return SIMDFloat3(_mm_sub_ps(m, v.m));
}

inline SIMDFloat3& VECTOR_CALL SIMDFloat3::operator-=(const SIMDFloat3 v)
{
	*this = SIMDFloat3(_mm_sub_ps(m, v.m));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator-() const
{
	return SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(-1)));
}

inline SIMDFloat3 SIMDFloat3::operator*(const float k) const
{
	return SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(k)));
}

inline SIMDFloat3 VECTOR_CALL operator*(const float k, const SIMDFloat3 v)
{
	return SIMDFloat3(_mm_mul_ps(v.m, _mm_set1_ps(k)));
}

inline SIMDFloat3& SIMDFloat3::operator*=(const float k)
{
	*this = SIMDFloat3(_mm_mul_ps(m, _mm_set1_ps(k)));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::operator/(const float k) const
{
	return SIMDFloat3(_mm_div_ps(m, _mm_set1_ps(k)));
}

inline SIMDFloat3& SIMDFloat3::operator/=(const float k)
{
	*this = SIMDFloat3(_mm_div_ps(m, _mm_set1_ps(k)));
	return *this;
}

inline bool VECTOR_CALL SIMDFloat3::equal(const SIMDFloat3 v, const float epsilon) const
{
	__m128 sub = _mm_sub_ps(m, v.m);

	__m128 abs = _mm_mul_ps(sub, sub);
	__m128 epsi = _mm_set1_ps(epsilon * epsilon);

	__m128 isUnder = _mm_cmple_ps(abs, epsi);
	return (_mm_movemask_ps(isUnder) & 0b0111) == 0b0111;
}

inline bool SIMDFloat3::isZero() const
{
	__m128 isEqual = _mm_cmpeq_ps(m, _mm_set1_ps(0));
	return (_mm_movemask_ps(isEqual) & 0b0111) == 0b0111;
}

inline SIMDFloat3 SIMDFloat3::length() const
{
	__m128 mul = _mm_dp_ps(m, m, 0b00111111);
	return _mm_sqrt_ps(mul);
}

inline SIMDFloat3 SIMDFloat3::squareLength() const
{
	return _mm_dp_ps(m, m, 0b00111111);
}

inline SIMDFloat3& SIMDFloat3::normalize()
{
	*this = SIMDFloat3(_mm_div_ps(m, length().m));
	return *this;
}

inline SIMDFloat3 SIMDFloat3::normalized() const
{
	return SIMDFloat3(_mm_div_ps(m, length().m));
}

inline float SIMDFloat3::getX() const
{
	return _mm_cvtss_f32(m);
}

inline float SIMDFloat3::getY() const
{
	__m128 shuffled = _mm_shuffle_ps(m, m, _MM_SHUFFLE(1, 1, 1, 1));
	return _mm_cvtss_f32(shuffled);
}

inline float SIMDFloat3::getZ() const
{
	__m128 shuffled = _mm_shuffle_ps(m, m, _MM_SHUFFLE(2, 2, 2, 2));
	return _mm_cvtss_f32(shuffled);
}

inline SIMDFloat3 VECTOR_CALL SIMDFloat3::Dot(const SIMDFloat3 v1, const SIMDFloat3 v2)
{
	return SIMDFloat3(_mm_dp_ps(v1.m, v2.m, 0b00111111));
}


inline SIMDFloat3 VECTOR_CALL SIMDFloat3::Cross(const SIMDFloat3 v1, const SIMDFloat3 v2)
{
	__m128 vTmp1 = _mm_shuffle_ps(v1.m, v1.m, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 vTmp2 = _mm_shuffle_ps(v2.m, v2.m, _MM_SHUFFLE(3, 1, 0, 2));

	__m128 vResult = _mm_mul_ps(vTmp1, vTmp2);

	vTmp1 = _mm_shuffle_ps(vTmp1, vTmp1, _MM_SHUFFLE(3, 0, 2, 1));
	vTmp2 = _mm_shuffle_ps(vTmp2, vTmp2, _MM_SHUFFLE(3, 1, 0, 2));

	vResult = _mm_sub_ps(vResult, _mm_mul_ps(vTmp1, vTmp2));
	return SIMDFloat3(vResult);
}

inline SIMDFloat3 VECTOR_CALL SIMDFloat3::Normalize(const SIMDFloat3 v)
{
	return SIMDFloat3(_mm_div_ps(v.m, v.length().m));
}

inline std::ostream& VECTOR_CALL operator<<(std::ostream& stream, SIMDFloat3 v)
{
	float num[4];
	_mm_store_ps(num, v.m);

	return stream << "(" << num[0] << ", " << num[1] << ", " << num[2] << ")";
}