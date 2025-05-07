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
            uint8_t getOct(u_int8_t value) const;
            bool operator<(const IP& other){
                if(ip_addr_.m_oct1 != other.ip_addr_.m_oct1){
                    return ip_addr_.m_oct1 < other.ip_addr_.m_oct1;
                }
                if(ip_addr_.m_oct2 != other.ip_addr_.m_oct2){
                    return ip_addr_.m_oct2 < other.ip_addr_.m_oct2;
                }
                if(ip_addr_.m_oct3 != other.ip_addr_.m_oct3){
                    return ip_addr_.m_oct3 < other.ip_addr_.m_oct3;
                }
                return ip_addr_.m_oct4 < other.ip_addr_.m_oct4;
            }
    };

}

#endif