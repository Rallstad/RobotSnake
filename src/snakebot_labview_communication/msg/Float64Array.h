#ifndef Float64Array_h
#define Float64Array_h

#include <wtf/TypedArrayBase.h>
#include <wtf/MathExtras.h>

namespace WTF {

class Float64Array : public TypedArrayBase<double> {
public:
    static inline PassRefPtr<Float64Array> create(unsigned length);
    static inline PassRefPtr<Float64Array> create(const double* array, unsigned length);
    static inline PassRefPtr<Float64Array> create(PassRefPtr<ArrayBuffer>, unsigned byteOffset, unsigned length);

    // Should only be used when it is known the entire array will be filled. Do
    // not return these results directly to JavaScript without filling first.
    static inline PassRefPtr<Float64Array> createUninitialized(unsigned length);

    using TypedArrayBase<double>::set;

    void set(unsigned index, double value)
    {
        if (index >= TypedArrayBase<double>::m_length)
            return;
        TypedArrayBase<double>::data()[index] = static_cast<double>(value);
    }

    inline PassRefPtr<Float64Array> subarray(int start) const;
    inline PassRefPtr<Float64Array> subarray(int start, int end) const;

    virtual ViewType getType() const
    {
        return TypeFloat64;
    }

private:
    inline Float64Array(PassRefPtr<ArrayBuffer>,
                 unsigned byteOffset,
                 unsigned length);
    // Make constructor visible to superclass.
    friend class TypedArrayBase<double>;
};

PassRefPtr<Float64Array> Float64Array::create(unsigned length)
{
    return TypedArrayBase<double>::create<Float64Array>(length);
}

PassRefPtr<Float64Array> Float64Array::create(const double* array, unsigned length)
{
    return TypedArrayBase<double>::create<Float64Array>(array, length);
}

PassRefPtr<Float64Array> Float64Array::create(PassRefPtr<ArrayBuffer> buffer, unsigned byteOffset, unsigned length)
{
    return TypedArrayBase<double>::create<Float64Array>(buffer, byteOffset, length);
}

PassRefPtr<Float64Array> Float64Array::createUninitialized(unsigned length)
{
    return TypedArrayBase<double>::createUninitialized<Float64Array>(length);
}

Float64Array::Float64Array(PassRefPtr<ArrayBuffer> buffer, unsigned byteOffset, unsigned length)
    : TypedArrayBase<double>(buffer, byteOffset, length)
{
}

PassRefPtr<Float64Array> Float64Array::subarray(int start) const
{
    return subarray(start, length());
}

PassRefPtr<Float64Array> Float64Array::subarray(int start, int end) const
{
    return subarrayImpl<Float64Array>(start, end);
}

} // namespace WTF

using WTF::Float64Array;

#endif // Float64Array_h