// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// encode_base
NumericVector encode_base(char base);
RcppExport SEXP _XalBio_encode_base(SEXP baseSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< char >::type base(baseSEXP);
    rcpp_result_gen = Rcpp::wrap(encode_base(base));
    return rcpp_result_gen;
END_RCPP
}
// encode_sequence
NumericVector encode_sequence(CharacterVector sequence, CharacterVector reverse, int gap);
RcppExport SEXP _XalBio_encode_sequence(SEXP sequenceSEXP, SEXP reverseSEXP, SEXP gapSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type sequence(sequenceSEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type reverse(reverseSEXP);
    Rcpp::traits::input_parameter< int >::type gap(gapSEXP);
    rcpp_result_gen = Rcpp::wrap(encode_sequence(sequence, reverse, gap));
    return rcpp_result_gen;
END_RCPP
}
// reverse_compliment
String reverse_compliment(CharacterVector sequence);
RcppExport SEXP _XalBio_reverse_compliment(SEXP sequenceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type sequence(sequenceSEXP);
    rcpp_result_gen = Rcpp::wrap(reverse_compliment(sequence));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_XalBio_encode_base", (DL_FUNC) &_XalBio_encode_base, 1},
    {"_XalBio_encode_sequence", (DL_FUNC) &_XalBio_encode_sequence, 3},
    {"_XalBio_reverse_compliment", (DL_FUNC) &_XalBio_reverse_compliment, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_XalBio(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
