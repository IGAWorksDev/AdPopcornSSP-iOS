Pod::Spec.new do |s|
s.name         = "AdPopcornSSP"
s.version      = "2.9.6"
s.summary      = "AdPopcornSSP.framework"
s.homepage     = "https://github.com/IGAWorksDev/AdPopcornSSP-iOS"
s.license      = {
    :type => 'Commercial',
    :text => <<-LICENSE
    All text and design is copyright 2006-2024 adpopcorn, Inc.
    All rights reserved.
    https://github.com/IGAWorksDev/AdPopcornSSP-iOS
    LICENSE
}
s.platform = :ios, '11.0'
s.author       = { "mick" => "mick@igaworks.com" }
s.source       = { :git => "https://github.com/IGAWorksDev/AdPopcornSSP-iOS.git", :tag => "#{s.version}" }
s.resources = "AdPopcornSSP.bundle"
s.ios.vendored_frameworks = "AdPopcornSSP.xcframework"
s.frameworks = 'AdSupport', 'MobileCoreServices', 'MessageUI', 'MediaPlayer', 'AVKit', 'AVFoundation', 'CoreMedia', 'CoreTelephony', 'SystemConfiguration', 'WebKit', 'Security', 'UIKit', 'CoreGraphics', 'QuartzCore'
s.libraries = 'xml2'
s.xcconfig     = { 'HEADER_SEARCH_PATHS' => '"$(SDKROOT)/usr/include/libxml2"' }
end
