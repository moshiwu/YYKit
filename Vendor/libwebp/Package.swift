// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "libwebp",
    platforms: [
        .iOS(.v15),
    ],
    products: [
        .library(
            name: "libwebp",
            targets: ["libwebp"]
        ),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "libwebp",
            dependencies: [],
            path: ".",
            exclude: [
                "src/mux",
                "src/demux",
                "src/dec/Makefile.am",
                "src/dsp/Makefile.am",
                "src/enc/Makefile.am",
                "src/utils/Makefile.am",
            ],
            sources: [
                "src/dec",
                "src/dsp",
                "src/enc",
                "src/utils",
            ],
            publicHeadersPath: "src/webp",
            cSettings: [
                .headerSearchPath("."),
                .headerSearchPath("src"),
                .headerSearchPath("src/dec"),
                .headerSearchPath("src/dsp"),
                .headerSearchPath("src/enc"),
                .headerSearchPath("src/utils"),
                .define("HAVE_CONFIG_H"),
                .define("WEBP_USE_THREAD"),
                .define("HAVE_PTHREAD"),
                .define("WEBP_USE_NEON"),
            ],
            linkerSettings: [
                .linkedFramework("CoreGraphics"),
                .linkedFramework("ImageIO"),
            ]
        ),
    ]
)
