// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "NHN Cloud SDK",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "nhncloud.ios.sdk",
            targets: [
                "NHN Cloud Common",
                "NHN Cloud Core",
                "NHN Cloud Push",
                "NHN Cloud Log & Crash",
                "NHN Cloud In App Purchase",
            ]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        .binaryTarget(
            name: "NHNCloudCommon",
            url: "",
            checksum: ""
        ),
        .target(
            name: "NHN Cloud Common",
            dependencies: []),
        .target(
            name: "NHN Cloud Core",
            dependencies: [
                "NHN Cloud Common"
            ]),
        .target(
            name: "NHN Cloud Push",
            dependencies: [
                "NHN Cloud Core"
            ]),
        .target(
            name: "NHN Cloud Log & Crash",
            dependencies: [
                "NHN Cloud Core"
            ]),
        .target(
            name: "NHN Cloud In App Purchase",
            dependencies: [
                "NHN Cloud Core"
            ]),
    ]
)
