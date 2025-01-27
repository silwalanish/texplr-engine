#include <texplr/core/renderer.h>

namespace texplr {

Renderer::Renderer(const RendererSpecification& specs, std::shared_ptr<VulkanContext> vulkanContext)
    : m_specs(specs)
    , m_vulkanContext(vulkanContext)
{
}

Renderer::~Renderer()
{
}

void Renderer::init()
{
}

void Renderer::destroy()
{
}

} // namespace texplr
