#include "cuda_kernels.ipp"

/// @brief Global CUDA kernels
/// @tparam T 
/// @tparam D 
/// @return 

std::size_t 
bindx(std::size_t bx, std::size_t by, std::size_t bz, 
    std::size_t nbx, std::size_t nby)
{
    return  bx + nbx * (by + nby * bz);
}

std::size_t
tindx(std::size_t x, std::size_t y, std::size_t z, 
    std::size_t npx, std::size_t npy)
{
    return  x + npx * (y + npy * z);
}

/*
template
__global__ void 
fill_device(const double &t_val, std::size_t npx, std::size_t npy, std::size_t npz, double* device_data);

template
void 
fill(const double &t_val, block<double,3>& cgrid, double* device_data);
*/

template
void 
operations_device(std::size_t npx, 
            std::size_t npy, 
            std::size_t xmin, 
            std::size_t xmax, 
            std::size_t ymin, 
            std::size_t ymax, 
            std::size_t zmin, 
            std::size_t zmax, 
            double* device_data_1, 
            double* device_data_2, 
            sycl::nd_item<3> item_ct);

template
void 
operations(block<double,3>& cgrid, double* device_data_1, double* device_data_2, sycl::queue& q);
