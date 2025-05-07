#ifndef HW2_VIEW_DATA_H_
#define HW2_VIEW_DATA_H_

#include <vector>
#include "ip.hpp"

namespace hw2{

    class ViewData {
        private:
        public:
            ViewData() = default;
            virtual ~ViewData() = default;
            void View1(const std::vector<hw2::IP>& data);
            void View3(const std::vector<hw2::IP>& data);
            void View4(const std::vector<hw2::IP>& data);
            void View2(const std::vector<hw2::IP>& data);
    };
}
#endif