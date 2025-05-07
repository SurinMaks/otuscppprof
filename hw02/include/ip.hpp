#ifndef HW2_IP_HPP_
#define HW2_IP_HPP_

#include <cstdint>
#include <string>

namespace hw2{

    class IP
    {
        private:
            struct ip_addr
            {
                uint8_t m_oct1;
                uint8_t m_oct2;
                uint8_t m_oct3;
                uint8_t m_oct4;
            } ip_addr_;

        public:
            IP() = default;
            virtual ~IP() = default;
            void ReadData(std::istream& input);
            std::string getIP() const;
            uint8_t getOct(uint8_t value) const;
            bool operator<(const IP& other);
    };

}

#endif