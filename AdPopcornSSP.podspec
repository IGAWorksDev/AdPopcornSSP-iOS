Pod::Spec.new do |s|
s.name         = "AdPopcornSSP"
s.version      = "2.4.1"
s.summary      = "AdPopcornSSP.framework"
s.homepage     = "https://github.com/IGAWorksDev/AdPopcornSSP-iOS"

s.license      = {
:type => 'Commercial',
:text => <<-LICENSE
All text and design is copyright 2006-2021 igaworks, Inc.

All rights reserved.

https://github.com/IGAWorksDev/AdPopcornSSP-iOS
LICENSE
}

s.platform = :ios, '9.0'
s.author       = { "mick" => "mick.kim@adpopcorn.com" }
s.source       = { :git => "https://github.com/IGAWorksDev/AdPopcornSSP-iOS.git", :tag => "#{s.version}" }
s.resources = "AdPopcornSSP.bundle"
s.ios.vendored_frameworks = 'AdPopcornSSP.framework'
s.frameworks = 'AdSupport', 'MobileCoreServices', 'MessageUI', 'MediaPlayer', 'AVKit', 'AVFoundation', 'CoreMedia', 'CoreTelephony', 'SystemConfiguration', 'WebKit'
s.libraries = 'xml2'
s.xcconfig     = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
}
s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
