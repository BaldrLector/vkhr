#ifndef VKPP_QUEUE_HH
#define VKPP_QUEUE_HH

#include <vkpp/semaphore.hh>
#include <vkpp/swap_chain.hh>
#include <vkpp/command_buffer.hh>
#include <vkpp/render_pass.hh>

#include <vulkan/vulkan.h>

#include <cstdint>

namespace vkpp {
    class Queue final {
    public:
        Queue() = default;

        Queue(const VkQueue& queue, std::uint32_t family_index);

        VkQueue& get_handle();

        std::uint32_t get_family_index() const;

        void submit(CommandBuffer& command_buffer,
                    Semaphore& wait,
                    VkPipelineStageFlags wait_stage,
                    Semaphore& signal);

        void wait_idle();

        void present(SwapChain& swap_chain,
                     std::uint32_t indices,
                     Semaphore& wait);

    private:
        std::uint32_t family_index { 42 };
        VkQueue handle { VK_NULL_HANDLE };
    };
}

#endif
