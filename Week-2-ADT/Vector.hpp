#ifndef VECTOR_HPP
#define VECTOR_HPP

/// @file

/// \brief
/// rational ADT
/// \details
/// This is an ADT that implements rational (fractional) values.
/// The counter and denominator are stored as two (signed) integers.
/// The appropriate constructors and operators are provided.
///
/// Rational values are always simplied (reduced): the counter
/// and denominator have no common factors.
class vector
{
public:
    int x;
    int y;
    vector(int x, int y)
        : x(x)
        , y(y)
    {
    }

    /// \brief
    /// output operator for a vector value
    /// \details
    /// This operator<< prints a constructor in the format
    /// [counter/denominator] where both values are printed as
    /// decimal values.
    friend std::ostream& operator<<(std::ostream& lhs, const vector& rhs)
    {
        return lhs << "(" << rhs.x << "/" << rhs.y << ")";
    }

    /// \brief
    /// compare two vector values
    /// \details
    /// This operator tests for equality. It returns true
    /// if and only if the counter and denminator of both
    /// operands are equal.
    bool operator==(const vector& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y);
    }

    /// \brief
    /// Add two vectors
    /// \details
    /// Add two vectors operator
    vector operator+(const vector& rhs) const
    {
        return vector(x + rhs.x, y + rhs.y);
    }

    /// \brief
    /// add a vector to another vector
    /// \details
    /// This operator+= adds a vector value a vector variable.
    vector& operator+=(const vector& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    /// \brief
    /// multiply by vector
    /// \details
    /// This vector* multiplies a vector value by a vector value.
    vector operator*(const vector& rhs) const
    {
        return vector(x * rhs.x, y * rhs.y);
    }

    /// \brief
    /// multiply a vector to another vector
    /// \details
    /// This vector* multiplies a vector value by a vector value.
    vector operator*=(const vector& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
};

#endif