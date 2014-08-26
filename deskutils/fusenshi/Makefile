# Created by: Masanori OZAWA (ozawa@ongs.co.jp)
# $FreeBSD$

PORTNAME=	fusenshi
PORTVERSION=	0.9.0
PORTREVISION=	12
CATEGORIES=	deskutils
MASTER_SITES=	http://www.ongs.co.jp/projects/fusenshi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Post-it(R) like application with network support

USES=		pkgconfig tar:tgz
USE_GNOME=	gtkmm24 gtksourceview libxml2
USE_XORG=	x11
MAKE_JOBS_UNSAFE=	yes

.ifdef WITHOUT_SSL
MAKE_ARGS+=	WITHOUT_SSL=yes
.else
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
.endif

NO_STAGE=	yes
post-install:
	@${STRIP_CMD} ${PREFIX}/bin/fusenshi

.include <bsd.port.mk>
