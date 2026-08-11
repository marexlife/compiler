
std::string Logger::mergeMessageWithSourceLocation(
    std::string_view message,
    const std::source_location &sourceLocation) {
    return std::format(
        "{}\n{}", message,
        Logger::sourceLocationToString(sourceLocation));
}

std::string Logger::sourceLocationToString(
    const std::source_location &sourceLocation) {
    return std::format(
        "at: {}, {}, {}:{}", sourceLocation.file_name(),
        sourceLocation.function_name(), sourceLocation.line(),
        sourceLocation.column());
}