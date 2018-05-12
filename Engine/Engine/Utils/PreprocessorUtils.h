#pragma once

#define SUBSTRINGIZE(what) #what
#define STRINGIZE(what) SUBSTRINGIZE(what)

#define WSUBSTRINGIZE(what) L#what
#define WSTRINGIZE(what) WSUBSTRINGIZE(what)

