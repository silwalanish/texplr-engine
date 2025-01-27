#include <texplr/core/vulkan/swap_chain.h>

#include <vulkan/vulkan.h>

namespace texplr {

SwapChain::SwapChain()
{
}

SwapChain::~SwapChain()
{
}

void SwapChain::init()
{
    VkSwapchainCreateInfoKHR createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    
}

void SwapChain::destroy()
{
}

} // namespace texplr
