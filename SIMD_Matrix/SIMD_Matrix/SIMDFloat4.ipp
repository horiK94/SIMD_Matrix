

inline SIMDFloat4::SIMDFloat4() : m(_mm_setzero_ps())
{
}

inline SIMDFloat4::SIMDFloat4(NothingInit)
{
}

inline SIMDFloat4::SIMDFloat4(float _x, float _y, float _z, float _w) : m(_mm_set_ps(_w, _z, _y, _x))
{
}

inline SIMDFloat4::SIMDFloat4(const SIMDFloat3 v, float w) : m(_mm_set_ps(w, v.storeValue(2), v.storeValue(1), v.storeValue(0)))
{
}

inline SIMDFloat4::SIMDFloat4(const float* e) : m(_mm_loadu_ps(e))
{
}

inline SIMDFloat4::SIMDFloat4(const __m128 e) : m(e)
{
}

inline SIMDFloat4 SIMDFloat4::operator+(const SIMDFloat4& v) const
{
	return SIMDFloat4(_mm_add_ps(m, v.m));
}

inline SIMDFloat4& SIMDFloat4::operator+=(const SIMDFloat4& v)
{
	*this = SIMDFloat4(_mm_add_ps(m, v.m));
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator+() const
{
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator-(const SIMDFloat4& v) const
{
	return SIMDFloat4(_mm_sub_ps(m, v.m));
}

inline SIMDFloat4& SIMDFloat4::operator-=(const SIMDFloat4& v)
{
	*this = SIMDFloat4(_mm_sub_ps(m, v.m));
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator-() const
{
	return SIMDFloat4(_mm_mul_ps(_mm_set1_ps(-1), m));
}

inline SIMDFloat4 SIMDFloat4::operator*(const float k) const
{
	return SIMDFloat4(_mm_mul_ps(_mm_set1_ps(k), m));
}

inline SIMDFloat4 operator*(const float k, const SIMDFloat4& v)
{
	return SIMDFloat4(_mm_mul_ps(_mm_set1_ps(k), v.m));
}

inline SIMDFloat4& SIMDFloat4::operator*=(const float k)
{
	*this = SIMDFloat4(_mm_mul_ps(_mm_set1_ps(k), m));
	return *this;
}

inline SIMDFloat4 SIMDFloat4::operator/(const float k) const
{
	return SIMDFloat4(_mm_div_ps(m, _mm_set1_ps(k)));
}

inline SIMDFloat4& SIMDFloat4::operator/=(const float k)
{
	*this = SIMDFloat4(_mm_div_ps(m, _mm_set1_ps(k)));
	return *this;
}

inline bool SIMDFloat4::equal(const SIMDFloat4& v, const float epsilon) const
{
	__m128 sub = _mm_sub_ps(m, v.m);

	__m128 abs = _mm_mul_ps(sub, sub);
	__m128 epsi = _mm_set1_ps(epsilon * epsilon);

	__m128 isUnder = _mm_cmple_ps(abs, epsi);

	return _mm_movemask_ps(isUnder) == 0b1111;
}

inline bool SIMDFloat4::isZero() const
{
	__m128 isEqual = _mm_cmpeq_ps(m, _mm_set1_ps(0));

	return _mm_movemask_ps(isEqual) == 0b1111;
}

inline SIMDFloat4 SIMDFloat4::length() const
{
	__m128 mul = _mm_dp_ps(m, m, 0b11111111);
	return SIMDFloat4(_mm_sqrt_ps(mul));
}

inline SIMDFloat4 SIMDFloat4::squareLength() const
{
	return SIMDFloat4(_mm_dp_ps(m, m, 0b11111111));
}

inline SIMDFloat4& SIMDFloat4::normalize()
{
	*this = SIMDFloat4(_mm_div_ps(m, length().m));
	return *this;
}

inline SIMDFloat4 SIMDFloat4::normalized() const
{
	return SIMDFloat4(_mm_div_ps(m, length().m));
}

inline float SIMDFloat4::getX() const
{
	return _mm_cvtss_f32(m); // __m128 の最初の要素を取り出す
}

inline float SIMDFloat4::getY() const
{
	__m128 yyyy = _mm_shuffle_ps(m, m, _MM_SHUFFLE(1, 1, 1, 1)); // { y, y, y, y }
	return _mm_cvtss_f32(yyyy);
}

inline float SIMDFloat4::getZ() const
{
	__m128 zzzz = _mm_shuffle_ps(m, m, _MM_SHUFFLE(2, 2, 2, 2)); // { z, z, z, z }
	return _mm_cvtss_f32(zzzz);
}

inline float SIMDFloat4::getW() const
{
	__m128 wwww = _mm_shuffle_ps(m, m, _MM_SHUFFLE(3, 3, 3, 3)); // { w, w, w, w }
	return _mm_cvtss_f32(wwww);
}

inline float SIMDFloat4::storeValue(int _index) const
{
	float num[4];
	_mm_store_ps(num, m);

	return num[_index];
}

inline SIMDFloat4 SIMDFloat4::Dot(const SIMDFloat4& v1, const SIMDFloat4& v2)
{
	//第3引数はどこまで内積計算を行うかを決定するマスク
	return SIMDFloat4(_mm_dp_ps(v1.m, v2.m, 0b11111111));
}

inline SIMDFloat4 SIMDFloat4::Normalize(const SIMDFloat4& v)
{
	return SIMDFloat4(_mm_div_ps(v.m, v.length().m));
}

inline std::ostream& operator<<(std::ostream& stream, const SIMDFloat4& v)
{
	float num[4];
	_mm_store_ps(num, v.m);

	return stream << "(" << num[0] << ", " << num[1] << ", " << num[2] << ", " << num[3] << ")";
}

