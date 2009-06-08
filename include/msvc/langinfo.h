#ifndef KDEWIN_LANGINFO_H
#define KDEWIN_LANGINFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <kdewin_export.h>
#include <nl_types.h>

KDEWIN_EXPORT char *nl_langinfo(nl_item);

#ifdef __cplusplus
}
#endif

#endif  // _LANGINFO_H
