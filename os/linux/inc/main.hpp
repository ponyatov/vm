/// @defgroup main main
/// @brief POSIX entry point (console app)
/// @ingroup lib
/// @{

/// @brief POSIX entry point (console app)
extern int main(int argc, char *argv[]);

/// @brief print command line argument
extern void arg(int argc, char *argv);

/// @brief system-wide init
extern void init();

/// @brief system-wide shutdown
extern void fini();

/// @}
