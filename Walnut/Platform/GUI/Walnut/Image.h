#pragma once

#include <string>

#include "vulkan/vulkan.h"

namespace Walnut {

	enum class ImageFormat
	{
		None = 0,
		RGBA,
		RGBA32F,
		RGBA16F,
		R32F,
		RG16F,
		R32UI
	};

	class Image
	{
	public:
		Image(std::string_view path);
		Image(uint32_t width, uint32_t height, ImageFormat format, const void* data = nullptr);
		~Image();

		void SetData(const void* data);

		VkDescriptorSet GetDescriptorSet() const { return m_DescriptorSet; }
		VkImage GetVkImage() const { return m_Image; }
		VkImageView GetVkImageView() const { return m_ImageView; }
		VkSampler GetVkSampler() const { return m_Sampler; }
		ImageFormat GetFormat() const { return m_Format; }

		void Resize(uint32_t width, uint32_t height);

		uint32_t GetWidth() const { return m_Width; }
		uint32_t GetHeight() const { return m_Height; }

		static void* Decode(const void* data, uint64_t length, uint32_t& outWidth, uint32_t& outHeight);
	private:
		void AllocateMemory(uint64_t size);
		void Release();
	private:
		uint32_t m_Width = 0, m_Height = 0;
		uint32_t m_MipLevels = 1;

		VkImage m_Image = nullptr;
		VkImageView m_ImageView = nullptr;
		VkDeviceMemory m_Memory = nullptr;
		VkSampler m_Sampler = nullptr;

		ImageFormat m_Format = ImageFormat::None;

		VkBuffer m_StagingBuffer = nullptr;
		VkDeviceMemory m_StagingBufferMemory = nullptr;

		size_t m_AlignedSize = 0;

		VkDescriptorSet m_DescriptorSet = nullptr;

		std::string m_Filepath;
	};

}



