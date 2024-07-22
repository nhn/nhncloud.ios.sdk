if [ -d "../CrashReporter-xcframework.zip" ]; then
    echo 'removed CrashReporter-xcframework.zip'
    rm -rf "../CrashReporter-xcframework.zip"
fi

if [ -d "../CrashReporter-framework.zip" ]; then
    echo 'removed CrashReporter-framework.zip'
    rm -rf "../CrashReporter-framework.zip"
fi

if [ -d "../CrashReporter-static.zip" ]; then
    echo 'removed CrashReporter-static.zip'
    rm -rf "../CrashReporter-static.zip"
fi

if [ -d "../CrashReporter-static-unreal.zip" ]; then
    echo 'removed CrashReporter-static-unreal.zip'
    rm -rf "../CrashReporter-static-unreal.zip"
fi

echo 'tar CrashReporter-xcframework.zip'
tar -cf ../CrashReporter-xcframework.zip \
    --exclude "./Tools" \
    --exclude "./iOS Framework" \
    --exclude "./Mac OS X Framework" \
    --exclude "./Static" \
    --exclude "./tvOS Framework" \
    --exclude "./zip.sh" .

echo 'tar CrashReporter-framework.zip'
tar -cf ../CrashReporter-framework.zip \
    --exclude "./Tools" \
    --exclude "./CrashReporter.xcframework" \
    --exclude "./Static" \
    --exclude "./zip.sh" .

cd Static

echo 'tar CrashReporter-static.zip'
tar -cf ../../CrashReporter-static.zip \
    --exclude "./Debug-iphoneos" \
    --exclude "./Release-iphoneos" \
    --exclude "./zip.sh" .

echo 'tar CrashReporter-static-unreal.zip'
tar -cf ../../CrashReporter-static-unreal.zip \
    --exclude "./libCrashReporter-iOS.a" \
    --exclude "./libCrashReporter-MacOSX-Static.a" \
    --exclude "./libCrashReporter-tvOS.a" \
    --exclude "./zip.sh" .
