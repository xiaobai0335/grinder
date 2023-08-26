#pragma once
struct FloatVector3D {
    float x, y, z;

    FloatVector3D() {}

    FloatVector3D(float x_val, float y_val, float z_val) : x(x_val), y(y_val), z(z_val) {}

    FloatVector3D subtract(const FloatVector3D& other) const {
        return FloatVector3D(x - other.x, y - other.y, z - other.z);
    }

    FloatVector3D add(const FloatVector3D& other) const {
        return FloatVector3D(x + other.x, y + other.y, z + other.z);
    }

    float dotProduct(const FloatVector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    float distance(const FloatVector3D& other) const {
        FloatVector3D diff = subtract(other);
        return diff.magnitude();
    }

    bool isZeroVector() {
        return x == 0 && y == 0 && z == 0;
    }

    void print() {
        std::cout
            << "X:" << x
            << " Y:" << y
            << " Z:" << z
            << "\n";
    }

    FloatVector2D to2D() {
        return FloatVector2D(x, y);
    }

    bool operator==(const FloatVector3D& other) const {
        float epsilon = 1e-5;
        return (std::abs(x - other.x) < epsilon)
            && (std::abs(y - other.y) < epsilon)
            && (std::abs(z - other.z) < epsilon);
    }

    bool operator!=(const FloatVector3D& other) const {
        return !(*this == other);
    }
};