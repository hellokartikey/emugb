include(FetchContent)
FetchContent_Declare(
  hk_signals 
  GIT_REPOSITORY https://github.com/hellokartikey/signals.git
  GIT_TAG main
  GIT_PROGRESS   TRUE
  GIT_SHALLOW    TRUE)
FetchContent_MakeAvailable(hk_signals)
