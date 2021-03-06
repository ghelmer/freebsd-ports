# $FreeBSD$

PORTNAME=	genact
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Nonsense activity generator

LICENSE=	APACHE20 BSD3CLAUSE ISCL MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro

PLIST_FILES=	bin/genact

CARGO_CRATES=	aho-corasick-0.7.13 \
		ansi_term-0.11.0 \
		anyhow-1.0.32 \
		async-attributes-1.1.1 \
		async-channel-1.4.0 \
		async-std-1.6.2 \
		async-task-3.0.0 \
		atomic-waker-1.0.0 \
		atty-0.2.14 \
		autocfg-1.0.0 \
		bitflags-1.2.1 \
		blocking-0.4.7 \
		bumpalo-3.4.0 \
		cache-padded-1.1.1 \
		cc-1.0.58 \
		cfg-if-0.1.10 \
		chrono-0.4.13 \
		clap-2.33.2 \
		concurrent-queue-1.2.2 \
		console_error_panic_hook-0.1.6 \
		crossbeam-utils-0.7.2 \
		ctrlc-3.1.6 \
		event-listener-2.3.3 \
		fake-2.2.3 \
		fastrand-1.3.4 \
		futures-0.3.5 \
		futures-channel-0.3.5 \
		futures-core-0.3.5 \
		futures-executor-0.3.5 \
		futures-io-0.3.5 \
		futures-lite-0.1.10 \
		futures-macro-0.3.5 \
		futures-sink-0.3.5 \
		futures-task-0.3.5 \
		futures-util-0.3.5 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.15 \
		humansize-1.1.0 \
		humantime-2.0.1 \
		idna-0.2.0 \
		instant-0.1.6 \
		js-sys-0.3.44 \
		kernel32-sys-0.2.2 \
		kv-log-macro-1.0.7 \
		lazy_static-1.4.0 \
		libc-0.2.74 \
		log-0.4.11 \
		matches-0.1.8 \
		memchr-2.3.3 \
		nix-0.17.0 \
		num-integer-0.1.43 \
		num-traits-0.2.12 \
		num_cpus-1.13.0 \
		once_cell-1.4.0 \
		parking-1.0.6 \
		percent-encoding-2.1.0 \
		pin-project-0.4.23 \
		pin-project-internal-0.4.23 \
		pin-project-lite-0.1.7 \
		pin-utils-0.1.0 \
		ppv-lite86-0.2.8 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro-hack-0.5.18 \
		proc-macro-nested-0.1.6 \
		proc-macro2-1.0.19 \
		progress_string-0.1.1 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_distr-0.2.2 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.3.9 \
		regex-syntax-0.6.18 \
		scoped-tls-1.0.0 \
		slab-0.4.2 \
		smol-0.1.18 \
		socket2-0.3.12 \
		strsim-0.8.0 \
		structopt-0.3.16 \
		structopt-derive-0.4.9 \
		syn-1.0.38 \
		term_size-1.0.0-beta1 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		time-0.1.43 \
		tinyvec-0.3.3 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.13 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.1.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		void-1.0.2 \
		waker-fn-1.0.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.67 \
		wasm-bindgen-backend-0.2.67 \
		wasm-bindgen-futures-0.4.17 \
		wasm-bindgen-macro-0.2.67 \
		wasm-bindgen-macro-support-0.2.67 \
		wasm-bindgen-shared-0.2.67 \
		web-sys-0.3.44 \
		wepoll-sys-stjepang-1.0.6 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-0.5.0

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/genact

.include <bsd.port.mk>
