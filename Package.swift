// swift-tools-version: 5.6
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "NHN Cloud SDK",
    products: [
        .library(
            name: "NHNCloudSDK",
            targets: ["NHNCloudCommon", "NHNCloudCore", "NHNCloudLogger", "NHNCloudOCR", "NHNCloudPush"]),
        .library(
            name: "NHNCloudCore",
            targets: ["NHNCloudCommon", "NHNCloudCore"]),
        .library(
            name: "NHNCloudLogger",
            targets: ["NHNCloudCommon", "NHNCloudCore", "NHNCloudLogger", "CrashReporter"]),
        .library(
            name: "NHNCloudOCR",
            targets: ["NHNCloudCommon", "NHNCloudCore", "NHNCloudOCR"]),
        .library(
            name: "NHNCloudPush",
            targets: ["NHNCloudCommon", "NHNCloudCore", "NHNCloudPush"]),
    ],
    dependencies: [
    ],
    targets: [
        .binaryTarget(name: "NHNCloudCommon", path: "xcframeworks/NHNCloudCommon.xcframework"),
        .binaryTarget(name: "NHNCloudCore", path: "xcframeworks/NHNCloudCore.xcframework"),
        .binaryTarget(name: "NHNCloudLogger", path: "xcframeworks/NHNCloudLogger.xcframework"),
        .binaryTarget(name: "NHNCloudOCR", path: "xcframeworks/NHNCloudOCR.xcframework"),
        .binaryTarget(name: "NHNCloudPush", path: "xcframeworks/NHNCloudPush.xcframework"),
        .binaryTarget(name: "CrashReporter", path: "External/CrashReporter/CrashReporter.xcframework")
    ]
)
