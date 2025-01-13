### CP vscode setup
This is a template for setting up vscode for competitive programming.

#### Vscode Extensions
- [CPH](https://marketplace.visualstudio.com/items?itemName=DivyanshuAgrawal.competitive-programming-helper)
- [Auto Snippets](https://marketplace.visualstudio.com/items?itemName=andreasxp.auto-snippets)

#### Browser Extensions
- [Competitive companion](https://chromewebstore.google.com/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl)
- [CPH Submit](https://chromewebstore.google.com/detail/cph-submit/ekplnobooikgpdbobcciehbhcmlklgnc)

#### Snippets settings at `settings.json`
```
  "cph.language.cpp.Args": "-DLOCAL",
  "cph.general.defaultLanguage": "cpp",
  "auto-snippets.snippets": [
    {
      "pattern": "**/*.cpp",
      "snippet": "cp-template",
    }
  ]
```
##### User snippets file can be found at `~/.config/Code/User/snippets/cpp.json`
```
	"cp-template": {
		"prefix": "cp",
		"body": [
			"#include<bits/stdc++.h>",
			"using namespace std;",
			"#ifdef LOCAL",
			"#include \"debug.h\"",
			"#else",
			"#define dbg(x...)",
			"#endif",
			"int32_t main(){",
            "",
			"    return 0;",
			"}"
		],
		"description": "Competitive programming template"
	}

```
