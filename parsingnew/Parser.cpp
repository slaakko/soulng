// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsing/Parser.hpp>

namespace soulng { namespace parsing {

Object::~Object()
{
}

Parser::Parser(const std::u32string& name_, const std::u32string& info_) : ParsingObject(name_, ObjectKind::parser), info(info_)
{
}

Parser::Parser(const std::u32string& name_, const std::u32string& info_, ObjectKind kind_) : ParsingObject(name_, kind_), info(info_)
{
}

} } // namespace soulng::parsing
