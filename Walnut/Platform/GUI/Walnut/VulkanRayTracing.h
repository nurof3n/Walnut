#pragma once

#include <vulkan/vulkan.h>

// Ray tracing extension function pointers
// Using pvk prefix to avoid conflicts with SDK stub declarations
extern PFN_vkGetBufferDeviceAddressKHR                pvkGetBufferDeviceAddressKHR;
extern PFN_vkCreateAccelerationStructureKHR           pvkCreateAccelerationStructureKHR;
extern PFN_vkDestroyAccelerationStructureKHR          pvkDestroyAccelerationStructureKHR;
extern PFN_vkGetAccelerationStructureBuildSizesKHR    pvkGetAccelerationStructureBuildSizesKHR;
extern PFN_vkGetAccelerationStructureDeviceAddressKHR pvkGetAccelerationStructureDeviceAddressKHR;
extern PFN_vkCmdBuildAccelerationStructuresKHR        pvkCmdBuildAccelerationStructuresKHR;
extern PFN_vkBuildAccelerationStructuresKHR           pvkBuildAccelerationStructuresKHR;
extern PFN_vkCreateRayTracingPipelinesKHR             pvkCreateRayTracingPipelinesKHR;
extern PFN_vkGetRayTracingShaderGroupHandlesKHR       pvkGetRayTracingShaderGroupHandlesKHR;
extern PFN_vkCmdTraceRaysKHR                          pvkCmdTraceRaysKHR;
