#include <cstdint>
#include <format>
#include <iostream>
#include <string>

namespace Memory {

    using address = std::uintptr_t;
    using byte = std::uint8_t;

    template <typename T>
    address decay(T* ptr) {
        return reinterpret_cast<address>(ptr);
    }

    template <typename T>
    std::string to_hex_str(const T& value) {
        std::stringstream stream;
        stream << std::setw(sizeof(T) * 2) << std::setfill('0') << std::hex
            << value;
        return stream.str();
    }

    template <typename T>
    void hex_dump(std::ostream& out,  T& data) {
        byte* bytes = reinterpret_cast<byte*>(&data);
        out << std::hex;
        for (int i = 0; i < sizeof(T); i++) {
            byte b = bytes[i];
            std::string byte_str = std::format("{:02X} ", b);
            out << byte_str;

            bool last_item = (i == sizeof(T) - 1);
            if (i % 16 == 15 && !last_item) {
                out << "\n";
            }
        }
        out << std::endl << std::dec;
    }
}
