#include <grid.hpp>
#include <iostream>
#include <sycl/sycl.hpp>
//#include <dpct/dpct.hpp>

/// @brief Global CUDA kernels
/// @tparam T 
/// @tparam D 
/// @return 

std::size_t 
bindx(std::size_t bx, std::size_t by, std::size_t bz, 
    std::size_t nbx, std::size_t nby);

std::size_t
tindx(std::size_t x, std::size_t y, std::size_t z, 
    std::size_t npx, std::size_t npy);
/*
template<typename T>
__global__ void 
fill_device(const T &t_val, std::size_t npx, std::size_t npy, std::size_t npz, T* device_data);

template<typename T, std::size_t D>
void 
fill(const T &t_val, block<T,D>& cgrid, T* device_data);
*/

template<typename T>
void 
operations_device(std::size_t npx, 
            std::size_t npy, 
            std::size_t xmin, 
            std::size_t xmax, 
            std::size_t ymin, 
            std::size_t ymax, 
            std::size_t zmin, 
            std::size_t zmax, 
            T* device_data_1, 
            T* device_data_2, 
            sycl::nd_item<3> item_ct);

template<typename T, std::size_t D>
void 
operations(block<T,D>& cgrid, T* device_data_1, T* device_data_2, sycl::queue& q);
