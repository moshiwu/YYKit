// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "YYKit",
    platforms: [
        .iOS(.v15),
    ],
    products: [
        .library(
            name: "YYKit",
            targets: ["YYKit"]
        ),
    ],
    dependencies: [
        .package(name: "libwebp", path: "Vendor/libwebp"),
    ],
    targets: [
        .target(
            name: "YYKit",
            dependencies: [
                "libwebp",
            ],
            path: "YYKit",
            exclude: [
                "Base/Foundation/NSObject+YYAddForARC.m",
                "Base/Foundation/NSThread+YYAdd.m",
                "../Demo",
            ],
            publicHeadersPath: "include",
            cSettings: [
                .headerSearchPath("."),
            ],
            linkerSettings: [
                .linkedFramework("UIKit"),
                .linkedFramework("CoreFoundation"),
                .linkedFramework("CoreGraphics"),
                .linkedFramework("CoreImage"),
                .linkedFramework("CoreText"),
                .linkedFramework("ImageIO"),
                .linkedFramework("Accelerate"),
                .linkedFramework("MobileCoreServices"),
                .linkedFramework("QuartzCore"),
                .linkedFramework("SystemConfiguration"),
                .linkedFramework("AssetsLibrary"),
                .linkedFramework("Photos"),
                .linkedFramework("WebKit"),
            ]
        ),
    ]
)
