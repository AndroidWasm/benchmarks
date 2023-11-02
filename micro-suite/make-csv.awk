BEGIN { i = 0 }
$1 == "wasm" { program = $2; wasm = 1; programs[i++] = program }
$1 == "native" { program = $2; wasm = 0 }
$1 == "user" { if (wasm) { wasmtime[program] = $2 } else { nativetime[program] = $2 } }
NF == 6 && $1 != "text" { wasmsize[$6] = $1 }
NF == 7 { nativesize[$6] = $1 }
END { for(j in programs) {
	p = programs[j]
	printf "%s,%s,%s,%s,%s\n", p, wasmtime[p], nativetime[p], wasmsize[p], nativesize[p]
      }
}
