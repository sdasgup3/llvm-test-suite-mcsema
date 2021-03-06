/* translation of file(s)
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f3.k"
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f2.k"
	"/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f1.k"
 */
/* generated by:
 *  @(#)$Author: criswell $
 */
#ifndef KC_TYPES_HEADER
#define KC_TYPES_HEADER

#define KIMWITUVERSIONMAJOR 2
#define KIMWITUVERSIONMINOR 3
#define KIMWITUVERSIONMICRO 8

#include <stdio.h>
#include <stddef.h>
#include <string>

namespace kc {

#ifndef INTEGER
# define INTEGER int
#endif
#ifndef REAL
# define REAL double
#endif

#ifdef KC_UNICODE

#define kc_t(TEXT) L ## TEXT
typedef wchar_t kc_char_t;
typedef std::wstring kc_string_t;

#if defined(_WIN32) && ! defined (__GNUC__)
#define kc_strlen wcslen
#define kc_strcmp wcscmp
#define kc_strcasecmp _wcsicmp
#define kc_strcpy wcscpy
#define kc_strncpy wcsncpy
#define kc_tolower towlower
#define kc_print_integer(buf,number) swprintf(buf,kc_t("%d"),number)
#define kc_print_real(buf,number) swprintf(buf,kc_t("%g"),number)

// needed for printdot and csgio only
inline
std::string kc_to_cstring(const std::wstring& s) {
    USES_CONVERSION;
    return W2CA(s.c_str());
}

// needed for csgio only
inline
std::wstring kc_to_wstring(const std::string& s) {
    USES_CONVERSION;
    return A2CW(s.c_str());
}

#else // !defined(_WIN32) || defined(__GNUC__)
// if you want to use UNICODE on other platforms you have to write
// the following functions on your own
int kc_strlen(const kc_char_t*);
int kc_strcmp(const kc_char_t*,const kc_char_t*);
int kc_strcasecmp(const kc_char_t*,const kc_char_t*);
int kc_strcpy(kc_char_t*,const kc_char_t*);
int kc_strncpy(kc_char_t*,const kc_char_t*, int);
kc_char_t kc_tolower(kc_char_t);
int kc_print_integer(kc_char_t* buffer, INTEGER number );
int kc_print_real(kc_char_t* buffer, REAL number);

// needed for printdot and csgio only
std::string kc_to_cstring(const std::wstring& );
// needed for csgio only
std::wstring kc_to_wstring(const std::string& );

#endif

#else // !KC_UNICODE

#define kc_t(TEXT) TEXT  
typedef char kc_char_t;
typedef std::string kc_string_t;

#define kc_strlen strlen
#define kc_strcmp strcmp
#if defined(_WIN32) && ! defined (__GNUC__)
#define kc_strcasecmp _stricmp
#else
#define kc_strcasecmp strcasecmp
#endif
#define kc_strcpy strcpy
#define kc_strncpy strncpy
#define kc_tolower tolower  
#define kc_print_integer(buf,number) sprintf(buf,kc_t("%d"),number)
#define kc_print_real(buf,number) sprintf(buf,kc_t("%g"),number)
#endif
class uview_class;
typedef uview_class& uview;
typedef const uview_class& c_uview;

typedef class printer_functor_class& printer_functor;
typedef void (*printer_function)(const kc_char_t*, uview);

class rview_class;
typedef rview_class& rview;
typedef const rview_class& c_rview;

}

// Some compilers know __attribute__. Right now we test for the GNU compiler
// and Intel's icc (for ia32) and ecc (for ia64).
#if !defined __GNUC__ && !defined __ICC && !defined __ECC
# define __attribute__(x)
#endif

// Since all definitions are in namespace kc now, there is no need
// give them a kc_ prefix. Old code may still rely on the prefix, so these
// macros are generated for backwards compatibility
#ifdef KC_DEPRECATED
#define kc_PhylumInfo           phylum_info
#define kc_OperatorInfo         operator_info
#define kc_last_uview           last_uview
#define kc_uviews               uviews
#define kc_rviews               rviews
#define kc_ht_reuse             ht_clear
#define kc_ht_clear             ht_clear
#define kc_ht_assign            ht_assign
#define kc_ht_assigned          ht_assigned
#define kc_phylum_nocasestring phylum_nocasestring
#define kc_tag_nocasestring_NoCaseStr impl_nocasestring_NoCaseStr
#define kc_phylum_casestring phylum_casestring
#define kc_tag_casestring__Str impl_casestring__Str
#define kc_phylum_real phylum_real
#define kc_tag_real__Real impl_real__Real
#define kc_phylum_integer phylum_integer
#define kc_tag_integer__Int impl_integer__Int
#define kc_phylum_voidptr phylum_voidptr
#define kc_tag_voidptr__VoidPtr impl_voidptr__VoidPtr
#define kc_phylum_line phylum_line
#define kc_tag_line_Line impl_line_Line
#define kc_phylum_term phylum_term
#define kc_tag_term_Number impl_term_Number
#define kc_tag_term_Ident impl_term_Ident
#define kc_phylum_expression phylum_expression
#define kc_tag_expression_Term impl_expression_Term
#define kc_tag_expression_Plus impl_expression_Plus
#define kc_tag_expression_Mul impl_expression_Mul
#define kc_tag_expression_Minus impl_expression_Minus
#define kc_tag_expression_Div impl_expression_Div
#define kc_tag_expression_Div2 impl_expression_Div2

#endif // KC_DEPRECATED

// Some compilers are too stupid to detect that a function will always return
// a proper value when it returns one in all branches of an if- or switch-
// statement (with final else or default, of course).
#if !defined __GNUC__
# define NORETURN throw 0;
#else
# define NORETURN
#endif

namespace kc {


typedef enum { one_before_first_phylum = 0 ,
    phylum_nocasestring = 1,
    phylum_casestring = 2,
    phylum_real = 3,
    phylum_integer = 4,
    phylum_voidptr = 5,
    phylum_line = 6,
    phylum_term = 7,
    phylum_expression = 8,
    last_phylum = 9
} enum_phyla;

typedef enum { one_before_first_operator = 0 ,
    sel_NoCaseStr = 1,
    sel__Str = 2,
    sel__Real = 3,
    sel__Int = 4,
    sel__VoidPtr = 5,
    sel_Line = 6,
    sel_Number = 7,
    sel_Ident = 8,
    sel_Term = 9,
    sel_Plus = 10,
    sel_Mul = 11,
    sel_Minus = 12,
    sel_Div = 13,
    sel_Div2 = 14,
    last_operator = 15
} enum_operators;

class impl_abstract_phylum;
typedef impl_abstract_phylum * abstract_phylum;
typedef const impl_abstract_phylum * c_abstract_phylum;
class impl_abstract_list;
typedef impl_abstract_list * abstract_list;
typedef const impl_abstract_list * c_abstract_list;

template <typename P, typename T>
P phylum_cast(T* t) {
    return static_cast<P>(t);
}
template <typename P, typename T>
const P phylum_cast(const T* t) {
    return static_cast<const P>(t);
}
class impl_nocasestring_NoCaseStr;
class impl_casestring__Str;
class impl_real__Real;
class impl_integer__Int;
class impl_voidptr__VoidPtr;
class impl_line;
class impl_term;
class impl_expression;


void kc_invalid_operator( const char *kc_func_prefix, enum_phyla kc_phy, int kc_line,
    const char *kc_file, enum_operators kc_oper ) __attribute__ ((noreturn));

typedef enum_phyla *enum_phyla_list;

/*
 * make sure that the first 'real' storage class _always_ gets a value > 0
 * and kc_not_uniq gets a value == 0
 * (because then we can use it as a C boolean)
 */
enum kc_storageclass_t {
    kc_not_uniq,
    uniq,
    last_storageclass
};

typedef struct {
    const char *name;			// name of the phylum
    enum_operators first_operator;	// index in operator_info[]
    enum_operators last_operator;	// index in operator_info[]
    kc_storageclass_t uniq_stored;	// storage class
} KC_PHYLUM_INFO;

typedef struct {
    const char *name;			// name of the operator
    size_t no_sons;			// number of sons
    bool atomicity;			// atomic type or not
    enum_phyla phylum;			// index in phylum_info[]
    enum_phyla_list subphylum;		// indexes in phylum_info[]
    int no_attrs;			// number of attributes
    enum_phyla_list attribute;		// indexes in phylum_info[]
    size_t size;			// size of operator (for statistics)
} KC_OPERATOR_INFO;

typedef enum_phyla_list KC_UNIQ_INFO;

extern KC_OPERATOR_INFO operator_info[];
extern KC_PHYLUM_INFO phylum_info[];
extern KC_UNIQ_INFO kc_UniqInfo[];

#define KC_OP_NAME(op) (operator_info[op].name)
#define KC_NO_SONS(prod) (operator_info[prod].no_sons)
#define KC_ATOMICITY(prod) (operator_info[prod].atomicity)

typedef class impl_kc_dotedgenode_t *kc_dotedgenode_t;

typedef impl_nocasestring_NoCaseStr *nocasestring;
typedef const impl_nocasestring_NoCaseStr *c_nocasestring;
typedef impl_casestring__Str *casestring;
typedef const impl_casestring__Str *c_casestring;
typedef impl_real__Real *real;
typedef const impl_real__Real *c_real;
typedef impl_integer__Int *integer;
typedef const impl_integer__Int *c_integer;
typedef impl_voidptr__VoidPtr *voidptr;
typedef const impl_voidptr__VoidPtr *c_voidptr;
typedef impl_line *line;
typedef const impl_line *c_line;
typedef impl_term *term;
typedef const impl_term *c_term;
typedef impl_expression *expression;
typedef const impl_expression *c_expression;

#define KC_NO_OF_OPERATORS 15


} // namespace kc
namespace kc { }
using namespace kc;
/* included stuff */
#line 15 "/home/ed/mcsema-testing/llvm-test-suite/MultiSource/Applications/kimwitu++/inputs/f2.k"
extern line TheLine;

#line  295 "testk.h"
/* end included stuff */


namespace kc {

#ifndef KC_NO_DEFAULT_IN_WITH
# define KC_NO_DEFAULT_IN_WITH "Internal Error: no default action defined in function %s at %s:%d\n"
#endif
void kc_no_default_in_with (const char*, int, const char*);
void kc_returnless_function (const char *, int, const char*);

#ifndef NDEBUG
# define assertCond(t) do {if (!(t)) kc_assertionFailed(__FILE__,__LINE__);}while(false)
# define assertReason(t,s) do {if (!(t)) kc_assertionReasonFailed(__FILE__,__LINE__,s);}while(false)
# define assertNonNull(p) do {if (p == 0) kc_assertionNonNullFailed(__FILE__,__LINE__,#p);}while(false)
# define assertPhylum(ptr,phy) do { \
    assertNonNull(ptr); \
    if (ptr->phylum()!=phy) \
	kc_assertionOperatorInPhylumFailed(ptr->prod_sel(),#ptr,"->prod_sel()","phy",__FILE__,__LINE__); \
} while(false)
#else
# define assertCond(t)
# define assertReason(t,s)
# define assertNonNull(ptr)
# define assertPhylum(op,phy)
#endif
#define assertionFailed(s) kc_assertionReasonFailed(__FILE__,__LINE__,s)

void kc_assertionFailed (const char*, int) __attribute__ ((noreturn));
void kc_assertionReasonFailed (const char*, int, const char*) __attribute__ ((noreturn));
void kc_assertionNonNullFailed (const char*, int, const char*) __attribute__ ((noreturn));
void kc_assertionOperatorInPhylumFailed (int, const char*, const char*, const char*, const char*, int) __attribute__ ((noreturn));

casestring mkcasestring( const kc_char_t *, int length = -1);
nocasestring mknocasestring( const kc_char_t *, int length = -1);
integer mkinteger( const INTEGER );
real mkreal( const REAL );
inline casestring _Str( const kc_char_t * cc) { return mkcasestring(cc); }
inline nocasestring NoCaseStr( const kc_char_t * cc) { return mknocasestring(cc); }
inline integer _Int( const INTEGER cc) { return mkinteger(cc); }
inline real _Real( const REAL cc) { return mkreal(cc); }
class impl_line_Line* Line (expression);
class impl_term_Number* Number (integer);
class impl_term_Ident* Ident (casestring);
class impl_expression_Term* Term (term);
class impl_expression_Plus* Plus (expression, expression);
class impl_expression_Mul* Mul (expression, expression);
class impl_expression_Minus* Minus (expression, expression);
class impl_expression_Div* Div (expression, expression);
class impl_expression_Div2* Div2 (expression, casestring, expression);

//namespace Phylum {

class impl_abstract_phylum {
public:
    virtual enum_operators prod_sel() const =0;
    static const enum_phyla phylum_sel_;
    enum_phyla phylum() const;
    const char* phylum_name() const;
    const char* op_name() const;
    virtual abstract_phylum subphylum(int) const;
    virtual void set_subphylum(int, abstract_phylum);
    void free(bool recursive=true);
    bool eq(c_abstract_phylum) const;
    void print();
    void fprint(FILE *);
    abstract_phylum copy(bool kc_copy_attributes) const;
    void unparse(printer_functor pf, uview uv)
	{ do_unparse(pf, uv); }
    void unparse(printer_function opf, uview uv);

    void printdot_add_edge (c_abstract_phylum, int, int*, kc_dotedgenode_t*, const char*) const;
    void do_printdot_id (FILE*, bool, c_abstract_phylum, int) const;
    void do_printdot (FILE*, bool, int*, kc_dotedgenode_t*, const char*, bool, bool, c_abstract_phylum, int) const;

    virtual void fprintdot(FILE *,
	const char *root_label_prefix, const char *edge_label_prefix, const char *edge_attributes,
	bool print_node_labels, bool use_context_when_sharing_leaves, bool print_prologue_and_epilogue) const =0;
    void CSGIOwrite(FILE *) const;
    virtual abstract_phylum rewrite(rview v) { return do_rewrite(v); }
    virtual abstract_phylum do_rewrite(rview) { return this;}
    // called if a subphylum of an op is rewritten and a new op is created by default rule
    virtual void rewrite_members(abstract_phylum from) {} 
    virtual void post_create(){}
    virtual ~impl_abstract_phylum() { }
private:
    virtual void do_unparse(printer_functor, uview) =0;
protected:
    virtual void default_unparse(printer_functor, uview);
};


class impl_abstract_list: public impl_abstract_phylum{
private:
    void fprint_list(FILE *);
    friend class impl_abstract_phylum;
protected:
    abstract_phylum do_concat(c_abstract_phylum other, enum_operators) const;
    abstract_phylum do_reverse(c_abstract_phylum tail, enum_operators) const;
    abstract_phylum do_map(abstract_phylum (*kc_fp)(abstract_phylum), enum_operators);
    abstract_phylum do_filter(bool (*kc_fp)(abstract_phylum), enum_operators);
    abstract_list   do_append(abstract_phylum, abstract_list);
    abstract_phylum do_merge(abstract_list,abstract_phylum (*kc_fp)(abstract_phylum,abstract_phylum), enum_operators);
    abstract_phylum do_reduce(abstract_phylum neutral, abstract_phylum (*kc_fp)(abstract_phylum,abstract_phylum));
public:
    virtual bool is_nil() const =0;
    virtual abstract_list reverse() const =0;
    int length() const;
    abstract_phylum last() const;
    // Non-virtual, non-existing... Type must be known exactly anyway because
    // of the function given as a parameter
    //virtual abstract_list map( abstract_phylum (*)( abstract_phylum )) =0;
    //virtual abstract_list filter(bool (*)(abstract_phylum)) =0;
    void freelist();
};

abstract_phylum kc_create(enum_operators createOp, abstract_phylum=0, abstract_phylum=0, abstract_phylum=0);
abstract_phylum& attributeOf(abstract_phylum kc_p, int no);

class impl_nocasestring_NoCaseStr;
typedef impl_nocasestring_NoCaseStr impl_nocasestring;
class impl_nocasestring_NoCaseStr:public impl_abstract_phylum{
public:
    enum_operators prod_sel() const
	{ return sel_NoCaseStr; }
    static const enum_phyla phylum_sel_;
private:
    explicit impl_nocasestring_NoCaseStr(const kc_char_t*);
    void make_own(int length);
    friend nocasestring mknocasestring(const kc_char_t*, int);
public:
    ~impl_nocasestring_NoCaseStr() {
#if defined (_MSC_VER) && _MSC_VER<1300
	delete [] (kc_char_t*)name;
#else
	delete [] name;
#endif
    }
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;

    nocasestring rewrite( rview )
	{ return this; }
    kc_char_t const* name;
private:
    void do_unparse(printer_functor, uview);
};
class impl_casestring__Str;
typedef impl_casestring__Str impl_casestring;
class impl_casestring__Str:public impl_abstract_phylum{
public:
    enum_operators prod_sel() const
	{ return sel__Str; }
    static const enum_phyla phylum_sel_;
private:
    explicit impl_casestring__Str(const kc_char_t*);
    void make_own(int length);
    friend casestring mkcasestring(const kc_char_t*, int);
public:
    ~impl_casestring__Str() {
#if defined (_MSC_VER) && _MSC_VER<1300
	delete [] (kc_char_t*)name;
#else
	delete [] name;
#endif
    }
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;

    casestring rewrite( rview )
	{ return this; }
    kc_char_t const* name;
private:
    void do_unparse(printer_functor, uview);
};
class impl_real__Real;
typedef impl_real__Real impl_real;
class impl_real__Real:public impl_abstract_phylum{
public:
    enum_operators prod_sel() const
	{ return sel__Real; }
    static const enum_phyla phylum_sel_;
    explicit impl_real__Real(REAL _value);
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;

    real rewrite( rview )
	{ return this; }
    REAL value;
private:
    void do_unparse(printer_functor, uview);
};
class impl_integer__Int;
typedef impl_integer__Int impl_integer;
class impl_integer__Int:public impl_abstract_phylum{
public:
    enum_operators prod_sel() const
	{ return sel__Int; }
    static const enum_phyla phylum_sel_;
    explicit impl_integer__Int(INTEGER _value);
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;

    integer rewrite( rview )
	{ return this; }
    INTEGER value;
private:
    void do_unparse(printer_functor, uview);
};
class impl_voidptr__VoidPtr;
typedef impl_voidptr__VoidPtr impl_voidptr;
class impl_voidptr__VoidPtr:public impl_abstract_phylum{
public:
    enum_operators prod_sel() const
	{ return sel__VoidPtr; }
    static const enum_phyla phylum_sel_;
    explicit impl_voidptr__VoidPtr(void* _pointer);
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;

    voidptr rewrite( rview )
	{ return this; }
    void* pointer;
private:
    void do_unparse(printer_functor, uview);
};
class impl_line: public impl_abstract_phylum{
public:
    static const enum_phyla phylum_sel_;
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;
    line rewrite(rview) =0;
};
class impl_line_Line:public impl_line{
public:
    enum_operators prod_sel() const
	{ return sel_Line; }
    explicit impl_line_Line(expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    line rewrite( rview );
    impl_expression* expression_1;
private:
    void do_unparse(printer_functor, uview);
};
class impl_term: public impl_abstract_phylum{
public:
    static const enum_phyla phylum_sel_;
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;
    term rewrite(rview) =0;
};
class impl_term_Ident:public impl_term{
public:
    enum_operators prod_sel() const
	{ return sel_Ident; }
    explicit impl_term_Ident(casestring);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    term rewrite( rview );
    impl_casestring* casestring_1;
private:
    void do_unparse(printer_functor, uview);
};
class impl_term_Number:public impl_term{
public:
    enum_operators prod_sel() const
	{ return sel_Number; }
    explicit impl_term_Number(integer);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    term rewrite( rview );
    impl_integer* integer_1;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression: public impl_abstract_phylum{
public:
    static const enum_phyla phylum_sel_;
    void fprintdot( FILE*, const char*, const char*, const char*, bool, bool, bool ) const;
    expression rewrite(rview) =0;
};
class impl_expression_Div2:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Div2; }
    explicit impl_expression_Div2(expression, casestring, expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_expression* expression_1;
    impl_casestring* casestring_1;
    impl_expression* expression_2;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression_Div:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Div; }
    explicit impl_expression_Div(expression, expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_expression* expression_1;
    impl_expression* expression_2;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression_Minus:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Minus; }
    explicit impl_expression_Minus(expression, expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_expression* expression_1;
    impl_expression* expression_2;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression_Mul:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Mul; }
    explicit impl_expression_Mul(expression, expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_expression* expression_1;
    impl_expression* expression_2;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression_Plus:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Plus; }
    explicit impl_expression_Plus(expression, expression);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_expression* expression_1;
    impl_expression* expression_2;
private:
    void do_unparse(printer_functor, uview);
};
class impl_expression_Term:public impl_expression{
public:
    enum_operators prod_sel() const
	{ return sel_Term; }
    explicit impl_expression_Term(term);
    abstract_phylum subphylum(int) const;
    void set_subphylum(int, abstract_phylum);

    expression rewrite( rview );
    impl_term* term_1;
private:
    void do_unparse(printer_functor, uview);
};

//} // namespace Phylum


extern bool kc_storageclass_still_uniq[];

typedef struct {
    int created;
    int existing_not_found;
    int free_called[2];
    int freed[2];
} KC_OPERATOR_STATISTICS;

#ifdef KC_STATISTICS
# define print_operator_statistics(kc_f) do_print_operator_statistics(kc_f)
void	do_print_operator_statistics(FILE*);
#else
# define print_operator_statistics(kc_f)
#endif

typedef class hashtable_struct_t* hashtable_t;
void	ht_static (kc_storageclass_t);
void	ht_dynamic (kc_storageclass_t);
void	ht_inc_level (kc_storageclass_t);
void	ht_dec_level (kc_storageclass_t);
void	ht_free_level (kc_storageclass_t);
hashtable_t	ht_create_simple ();
hashtable_t	ht_assign (hashtable_t, kc_storageclass_t, bool still_unique=false);
hashtable_t	ht_assigned (kc_storageclass_t);
void	ht_clear (hashtable_t);
void	ht_delete (hashtable_t);
const char *phylumname_or_error ( enum_phyla );
const char *kc_operatorname_or_error ( enum_operators );


void fprintdotprologue ( FILE* );
void fprintdotepilogue ( FILE* );

} // namespace kc
#endif // KC_TYPES_HEADER
