/* translation of file(s)
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f3.k"
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f2.k"
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f1.k"
 */
/* generated by:
 *  @(#)$Author: criswell $
 */
#ifndef KC_CSGIO_HEADER
#define KC_CSGIO_HEADER
#include "testk.h"    // in case a user forgets


namespace kc {

extern const char *kc_csgio_err_reason;

typedef enum {
    KC_CSGIOSTATUS_NO_ERR = 0,
    KC_CSGIOSTATUS_SCAN_ERR_1, KC_CSGIOSTATUS_SCAN_ERR_2, KC_CSGIOSTATUS_SCAN_ERR_3,
    KC_CSGIOSTATUS_SCAN_ERR_4, KC_CSGIOSTATUS_SCAN_ERR_5, KC_CSGIOSTATUS_GRAM_INCONSISTENT,
    KC_CSGIOSTATUS_ROK, KC_CSGIOSTATUS_ILLEGAL_OPTION, KC_CSGIOSTATUS_TOO_MANY_OPERATORS,
    KC_CSGIOSTATUS_WOK, KC_CSGIOSTATUS_TXT_FILE_INPUT, KC_CSGIOSTATUS_SYNTAX_ERROR,
    KC_CSGIOSTATUS_ILLEGAL_CONTEXT, KC_CSGIOSTATUS_PREMATURE_EOF,
    KC_CSGIOSTATUS_UNEXP_FATHER_MARK
} KC_IO_STATUS;

// XXX Needs to be extended
struct IO_exception {
    IO_exception(KC_IO_STATUS _io_status, const char* _err_reason=kc_csgio_err_reason, int _line=0)
    : io_status(_io_status), err_reason(_err_reason), line(_line) { }
    KC_IO_STATUS io_status;
    const char *err_reason;
    int line;
};

char* IO_exception2char(IO_exception);

#if defined(__GNUC__) && __GNUC__<3
extern void CSGIOreadphylum(FILE*, abstract_phylum&, enum_phyla);
#endif

template<typename P> void
CSGIOread(FILE* kc_stream, P &kc_p)
{
    abstract_phylum kc_value;
#if !(defined(__GNUC__) && __GNUC__<3)
    extern void CSGIOreadphylum(FILE*, abstract_phylum&, enum_phyla);
#endif
    CSGIOreadphylum( kc_stream, kc_value, kc_p->phylum_sel_ );
    // Cast _could_ be static, but just to be completely sure
    if (dynamic_cast<P>(kc_value)==0)
	throw IO_exception(KC_CSGIOSTATUS_SCAN_ERR_5, "Internal problem: Wrong phylum type created.");
    kc_p = dynamic_cast<P>(kc_value);
}


} // namespace kc
#endif // KC_CSGIO_HEADER

