/**
 *  Copyright (C) 2015 Topology LP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef BONEFISH_DAEMON_OPTIONS_HPP
#define BONEFISH_DAEMON_OPTIONS_HPP

#include <cstdint>
#include <string>
#include <vector>

namespace bonefish {

/**
 * @brief Fill these in as desired and pass them to daemon on construction.
 */
class daemon_options
{
public:
    daemon_options();

    /// Set the WAMP realm. Must be set for the router to start.
    void set_realm(const std::string& realm) { m_realm = realm; }
    std::string realm() const { return m_realm; }

    /// Enable or disable debugging. Default value is disabled.
    void set_debug_enabled(bool enabled) { m_debug_enabled = enabled; }
    bool is_debug_enabled() const { return m_debug_enabled; }

    /// Enable or disable websocket support. Default value is disabled.
    /// At least one transport has to be enabled for the router to start.
    void set_websocket_enabled(bool enabled) { m_websocket_enabled = enabled; }
    bool is_websocket_enabled() const { return m_websocket_enabled; }

    /// Enable or disable websocketsecure support. Default value is disabled.
    /// At least one transport has to be enabled for the router to start.
    void set_websocketsecure_enabled(bool enabled) { m_websocketsecure_enabled = enabled; }
    bool is_websocketsecure_enabled() const { return m_websocketsecure_enabled; }

    /// Set the websocket port. Must be nonzero if websocket support is enabled.
    void set_websocket_port(std::uint16_t port) { m_websocket_port = port; }
    std::uint16_t websocket_port() const { return m_websocket_port; }

    /// Set the websocket secure port. Must be nonzero if websocket secure support is enabled.
    void set_websocketsecure_port(std::uint16_t port) { m_websocketsecure_port = port; }
    std::uint16_t websocketsecure_port() const { return m_websocketsecure_port; }

    /// Set the websocket secure keyfile path. Must be set if websocket secure support is enabled.
    void set_websocketsecure_key_path(const std::string& path) { m_websocketsecure_key_path = path; }
    const std::string& websocketsecure_key_path() const { return m_websocketsecure_key_path; }

    /// Set the websocket secure certificate path. Must be set if websocket secure support is enabled.
    void set_websocketsecure_cert_path(const std::string& path) { m_websocketsecure_cert_path = path; }
    const std::string& websocketsecure_cert_path() const { return m_websocketsecure_cert_path; }

    /// Enable or disable rawsocket support. Default value is disabled.
    /// At least one transport has to be enabled for the router to start.
    void set_rawsocket_enabled(bool enabled) { m_rawsocket_enabled = enabled; }
    bool is_rawsocket_enabled() const { return m_rawsocket_enabled; }

    /// Set the rawsocket port. Must be nonzero if rawsocket support is enabled.
    void set_rawsocket_port(std::uint16_t port) { m_rawsocket_port = port; }
    std::uint16_t rawsocket_port() const { return m_rawsocket_port; }

    /// Set the rawsocket uds path. Must be nonzero if rawsocket support is enabled.
    void set_rawsocket_path(const std::string& path) { m_rawsocket_path = path; }
    const std::string& rawsocket_path() const { return m_rawsocket_path; }

    /// Enable or disable JSON serialization support. Default value is enabled.
    /// At least one serialization method has to be enabled for the router to start.
    void set_json_serialization_enabled(bool enabled) { m_json_serialization_enabled = enabled; }
    bool is_json_serialization_enabled() const { return m_json_serialization_enabled; }

    /// Enable or disable msgpack serialization support. Default value is enabled.
    /// At least one serialization method has to be enabled for the router to start.
    void set_msgpack_serialization_enabled(bool enabled) { m_msgpack_serialization_enabled = enabled; }
    bool is_msgpack_serialization_enabled() const { return m_msgpack_serialization_enabled; }

    std::vector<std::string> problems() const;

private:
    std::string m_realm;
    bool m_debug_enabled;
    std::uint16_t m_websocket_port;
    std::uint16_t m_websocketsecure_port;
    std::uint16_t m_rawsocket_port;
    std::string m_rawsocket_path;
    std::string m_websocketsecure_key_path;
    std::string m_websocketsecure_cert_path;
    bool m_websocket_enabled;
    bool m_websocketsecure_enabled;
    bool m_rawsocket_enabled;
    bool m_json_serialization_enabled;
    bool m_msgpack_serialization_enabled;
};

} // namespace bonefish

#endif // BONEFISH_DAEMON_OPTIONS_HPP
