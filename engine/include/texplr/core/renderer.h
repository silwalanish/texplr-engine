#pragma once

#include <memory>

#include "surface/vulkan_context.h"

namespace texplr {

struct RendererSpecification {};

class Renderer {
public:
    Renderer(const RendererSpecification& specs,  std::shared_ptr<VulkanContext> vulkanContext);
    ~Renderer();

    void init();
    void destroy();

private:
    RendererSpecification m_specs;
    std::shared_ptr<VulkanContext> m_vulkanContext;

};

} // namespace texplr
