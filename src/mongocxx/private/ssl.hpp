// Copyright 2015 MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <mongocxx/options/ssl.hpp>

#include <mongocxx/private/libmongoc.hpp>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN
namespace options {

::mongoc_ssl_opt_t make_ssl_opts(const ssl& ssl_opts) {
    ::mongoc_ssl_opt_t out;
    if (ssl_opts.pem_file()) {
        out.pem_file = ssl_opts.pem_file()->c_str();
    }
    if (ssl_opts.pem_password()) {
        out.pem_pwd = ssl_opts.pem_password()->c_str();
    }
    if (ssl_opts.ca_file()) {
        out.ca_file = ssl_opts.ca_file()->c_str();
    }
    if (ssl_opts.ca_dir()) {
        out.ca_dir = ssl_opts.ca_dir()->c_str();
    }
    if (ssl_opts.weak_cert_validation()) {
        out.weak_cert_validation = *(ssl_opts.weak_cert_validation());
    }
    return out;
}

}  // namespace options
MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx
