#ifndef CATA_TOOLS_CLANG_TIDY_PLUGIN_HEADERGUARDCHECK_H
#define CATA_TOOLS_CLANG_TIDY_PLUGIN_HEADERGUARDCHECK_H

#include <clang-tidy/ClangTidy.h>
#include <clang-tidy/ClangTidyCheck.h>

namespace clang
{
namespace tidy
{
namespace cata
{

/// Finds and fixes header guards.
/// Based loosely on the LLVM version.
class CataHeaderGuardCheck : public ClangTidyCheck
{
    public:
        CataHeaderGuardCheck( StringRef Name, ClangTidyContext *Context );
        void registerPPCallbacks( const SourceManager &, Preprocessor *, Preprocessor * ) override;
};

} // namespace cata
} // namespace tidy
} // namespace clang

#endif // CATA_TOOLS_CLANG_TIDY_PLUGIN_HEADERGUARDCHECK_H
