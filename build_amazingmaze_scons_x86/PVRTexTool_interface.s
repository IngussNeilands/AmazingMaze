	.file	"PVRTexTool_interface.cpp"
	.text
.Ltext0:
	.local	_ZL5g_Ext
	.comm	_ZL5g_Ext,8,4
	.local	_ZL8g_GotExt
	.comm	_ZL8g_GotExt,1,1
	.local	_ZL10g_TriedExt
	.comm	_ZL10g_TriedExt,1,1
	.local	_ZL15g_TriedNoMsgExt
	.comm	_ZL15g_TriedNoMsgExt,1,1
	.section	.rodata
	.align 4
.LC0:
	.string	"error loading extension: PVRTexTool"
	.text
	.type	_ZL8_extLoadv, @function
_ZL8_extLoadv:
.LFB21:
	.file 1 "/Applications/Marmalade.app/Contents/extensions/PVRTexTool/interface/PVRTexTool_interface.cpp"
	.loc 1 43 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	leal	-36(%esp), %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
.LBB2:
.LBB3:
	.loc 1 44 0
	movzbl	_ZL8g_GotExt@GOTOFF(%ebx), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L2
	.loc 1 44 0 is_stmt 0 discriminator 1
	movzbl	_ZL10g_TriedExt@GOTOFF(%ebx), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L2
.LBB4:
	.loc 1 46 0 is_stmt 1
	movl	$8, 8(%esp)
	leal	_ZL5g_Ext@GOTOFF(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	$-1229730132, (%esp)
	call	s3eExtGetHash@PLT
	movl	%eax, -12(%ebp)
	.loc 1 47 0
	cmpl	$0, -12(%ebp)
	jne	.L3
	.loc 1 48 0
	movb	$1, _ZL8g_GotExt@GOTOFF(%ebx)
	jmp	.L4
.L3:
	.loc 1 50 0
	leal	.LC0@GOTOFF(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	$2, (%esp)
	call	s3eDebugAssertShow@PLT
.L4:
	.loc 1 52 0 discriminator 1
	movb	$1, _ZL10g_TriedExt@GOTOFF(%ebx)
	.loc 1 53 0 discriminator 1
	movb	$1, _ZL15g_TriedNoMsgExt@GOTOFF(%ebx)
.L2:
.LBE4:
.LBE3:
	.loc 1 56 0
	movzbl	_ZL8g_GotExt@GOTOFF(%ebx), %eax
.LBE2:
	.loc 1 57 0
	leal	36(%esp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE21:
	.size	_ZL8_extLoadv, .-_ZL8_extLoadv
	.type	_ZL13_extLoadNoMsgv, @function
_ZL13_extLoadNoMsgv:
.LFB22:
	.loc 1 60 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	leal	-36(%esp), %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
.LBB5:
.LBB6:
	.loc 1 61 0
	movzbl	_ZL8g_GotExt@GOTOFF(%ebx), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L7
	.loc 1 61 0 is_stmt 0 discriminator 1
	movzbl	_ZL15g_TriedNoMsgExt@GOTOFF(%ebx), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L7
.LBB7:
	.loc 1 63 0 is_stmt 1
	movl	$8, 8(%esp)
	leal	_ZL5g_Ext@GOTOFF(%ebx), %eax
	movl	%eax, 4(%esp)
	movl	$-1229730132, (%esp)
	call	s3eExtGetHash@PLT
	movl	%eax, -12(%ebp)
	.loc 1 64 0
	cmpl	$0, -12(%ebp)
	jne	.L8
	.loc 1 65 0
	movb	$1, _ZL8g_GotExt@GOTOFF(%ebx)
.L8:
	.loc 1 66 0
	movb	$1, _ZL15g_TriedNoMsgExt@GOTOFF(%ebx)
	.loc 1 67 0
	movzbl	_ZL10g_TriedExt@GOTOFF(%ebx), %eax
	testb	%al, %al
	je	.L9
	.loc 1 68 0
	movb	$1, _ZL10g_TriedExt@GOTOFF(%ebx)
.L9:
.L7:
.LBE7:
.LBE6:
	.loc 1 71 0
	movzbl	_ZL8g_GotExt@GOTOFF(%ebx), %eax
.LBE5:
	.loc 1 72 0
	leal	36(%esp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE22:
	.size	_ZL13_extLoadNoMsgv, .-_ZL13_extLoadNoMsgv
	.globl	PVRTexToolAvailable
	.hidden	PVRTexToolAvailable
	.type	PVRTexToolAvailable, @function
PVRTexToolAvailable:
.LFB23:
	.loc 1 75 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	leal	-4(%esp), %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 76 0
	call	_ZL13_extLoadNoMsgv
	.loc 1 77 0
	movzbl	_ZL8g_GotExt@GOTOFF(%ebx), %eax
	testb	%al, %al
	je	.L12
	.loc 1 77 0 is_stmt 0 discriminator 1
	movl	$1, %eax
	jmp	.L13
.L12:
	.loc 1 77 0 discriminator 2
	movl	$0, %eax
.L13:
	.loc 1 78 0 is_stmt 1 discriminator 3
	leal	4(%esp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE23:
	.size	PVRTexToolAvailable, .-PVRTexToolAvailable
	.section	.rodata
.LC1:
	.string	"PVRTEXTOOL_VERBOSE"
	.align 4
.LC2:
	.string	"calling PVRTexTool[0] func: PVRTexToolConvert"
	.text
	.globl	PVRTexToolConvert
	.hidden	PVRTexToolConvert
	.type	PVRTexToolConvert, @function
PVRTexToolConvert:
.LFB24:
	.loc 1 81 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	leal	-36(%esp), %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
.LBB8:
	.loc 1 82 0
	movl	$1, 4(%esp)
	leal	.LC1@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceIsChannelOn@PLT
	testb	%al, %al
	setne	%al
	testb	%al, %al
	je	.L16
	.loc 1 82 0 is_stmt 0 discriminator 1
	leal	.LC1@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceSetTraceChannel@PLT
	leal	.LC2@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceLinePrintf@PLT
.L16:
	.loc 1 84 0 is_stmt 1
	call	_ZL8_extLoadv
	xorl	$1, %eax
	testb	%al, %al
	je	.L17
	.loc 1 85 0
	movl	$0, %eax
	jmp	.L18
.L17:
	.loc 1 88 0
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	call	s3eDeviceLoaderCallStart@PLT
	.loc 1 91 0
	movl	_ZL5g_Ext@GOTOFF(%ebx), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	movl	%eax, -12(%ebp)
	.loc 1 94 0
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	call	s3eDeviceLoaderCallDone@PLT
	.loc 1 97 0
	movl	-12(%ebp), %eax
.L18:
.LBE8:
	.loc 1 98 0
	leal	36(%esp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE24:
	.size	PVRTexToolConvert, .-PVRTexToolConvert
	.section	.rodata
	.align 4
.LC3:
	.string	"calling PVRTexTool[1] func: PVRTexToolFree"
	.text
	.globl	PVRTexToolFree
	.hidden	PVRTexToolFree
	.type	PVRTexToolFree, @function
PVRTexToolFree:
.LFB25:
	.loc 1 101 0
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	leal	-20(%esp), %esp
	.cfi_offset 3, -12
	call	__x86.get_pc_thunk.bx
	addl	$_GLOBAL_OFFSET_TABLE_, %ebx
	.loc 1 102 0
	movl	$1, 4(%esp)
	leal	.LC1@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceIsChannelOn@PLT
	testb	%al, %al
	setne	%al
	testb	%al, %al
	je	.L20
	.loc 1 102 0 is_stmt 0 discriminator 1
	leal	.LC1@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceSetTraceChannel@PLT
	leal	.LC3@GOTOFF(%ebx), %eax
	movl	%eax, (%esp)
	call	IwDebugTraceLinePrintf@PLT
.L20:
	.loc 1 104 0 is_stmt 1
	call	_ZL8_extLoadv
	xorl	$1, %eax
	testb	%al, %al
	je	.L21
	.loc 1 105 0
	jmp	.L19
.L21:
	.loc 1 108 0
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	call	s3eDeviceLoaderCallStart@PLT
	.loc 1 111 0
	movl	4+_ZL5g_Ext@GOTOFF(%ebx), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	call	*%eax
	.loc 1 114 0
	movl	$0, 4(%esp)
	movl	$1, (%esp)
	call	s3eDeviceLoaderCallDone@PLT
	.loc 1 117 0
	nop
.L19:
	.loc 1 118 0
	leal	20(%esp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE25:
	.size	PVRTexToolFree, .-PVRTexToolFree
	.section	.text.__x86.get_pc_thunk.bx,"axG",@progbits,__x86.get_pc_thunk.bx,comdat
	.globl	__x86.get_pc_thunk.bx
	.hidden	__x86.get_pc_thunk.bx
	.type	__x86.get_pc_thunk.bx, @function
__x86.get_pc_thunk.bx:
.LFB26:
	.cfi_startproc
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	movl	(%esp), %ebx
	ret
	.cfi_endproc
.LFE26:
	.text
.Letext0:
	.file 2 "/Applications/Marmalade.app/Contents/s3e/h/s3eTypes.h"
	.file 3 "/Applications/Marmalade.app/Contents/s3e/h/s3eDebug.h"
	.file 4 "/Applications/Marmalade.app/Contents/s3e/h/std/c++/typeinfo.h"
	.file 5 "/Applications/Marmalade.app/Contents/s3e/h/std/c++/exception"
	.file 6 "/Applications/Marmalade.app/Contents/s3e/h/std/c++/typeinfo"
	.file 7 "/Applications/Marmalade.app/Contents/s3e/h/std/c++/stl/_config.h"
	.file 8 "/Applications/Marmalade.app/Contents/extensions/PVRTexTool/h/PVRTexTool.h"
	.file 9 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x3b2
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF53
	.byte	0x4
	.long	.LASF54
	.long	.LASF55
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF4
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.long	.LASF8
	.uleb128 0x4
	.long	.LASF11
	.byte	0x2
	.byte	0x7e
	.long	0x25
	.uleb128 0x5
	.long	.LASF12
	.byte	0x4
	.byte	0x2
	.byte	0xea
	.long	0x8f
	.uleb128 0x6
	.long	.LASF9
	.sleb128 0
	.uleb128 0x6
	.long	.LASF10
	.sleb128 1
	.byte	0
	.uleb128 0x4
	.long	.LASF12
	.byte	0x2
	.byte	0xee
	.long	0x76
	.uleb128 0x4
	.long	.LASF13
	.byte	0x2
	.byte	0xf3
	.long	0x6b
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF14
	.uleb128 0x7
	.long	.LASF15
	.byte	0x4
	.byte	0x3
	.value	0x116
	.long	0xcc
	.uleb128 0x6
	.long	.LASF16
	.sleb128 0
	.uleb128 0x6
	.long	.LASF17
	.sleb128 1
	.uleb128 0x6
	.long	.LASF18
	.sleb128 2
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF19
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF20
	.uleb128 0x8
	.string	"std"
	.byte	0x9
	.byte	0
	.long	0x106
	.uleb128 0x9
	.long	.LASF21
	.uleb128 0x9
	.long	.LASF22
	.uleb128 0xa
	.byte	0x4
	.byte	0x17
	.long	0xe5
	.uleb128 0x9
	.long	.LASF23
	.uleb128 0x9
	.long	.LASF24
	.uleb128 0x9
	.long	.LASF25
	.byte	0
	.uleb128 0xb
	.long	.LASF27
	.byte	0x7
	.value	0x1e9
	.long	0xda
	.uleb128 0xc
	.long	.LASF26
	.byte	0x7
	.value	0x222
	.long	0x150
	.uleb128 0xa
	.byte	0x5
	.byte	0x4e
	.long	0xe5
	.uleb128 0xa
	.byte	0x5
	.byte	0x4f
	.long	0xea
	.uleb128 0xa
	.byte	0x5
	.byte	0x4e
	.long	0xe5
	.uleb128 0xa
	.byte	0x5
	.byte	0x4f
	.long	0xea
	.uleb128 0xa
	.byte	0x6
	.byte	0x2f
	.long	0xf6
	.uleb128 0xa
	.byte	0x6
	.byte	0x33
	.long	0xfb
	.uleb128 0xa
	.byte	0x6
	.byte	0x3d
	.long	0x100
	.byte	0
	.uleb128 0xb
	.long	.LASF28
	.byte	0x7
	.value	0x224
	.long	0x112
	.uleb128 0xd
	.long	.LASF41
	.byte	0x7c
	.byte	0x8
	.byte	0x24
	.long	0x1d5
	.uleb128 0xe
	.long	.LASF29
	.byte	0x8
	.byte	0x2a
	.long	0x1d5
	.byte	0
	.uleb128 0xe
	.long	.LASF30
	.byte	0x8
	.byte	0x2f
	.long	0x1e5
	.byte	0x4
	.uleb128 0xe
	.long	.LASF31
	.byte	0x8
	.byte	0x35
	.long	0x48
	.byte	0x8
	.uleb128 0xe
	.long	.LASF32
	.byte	0x8
	.byte	0x3a
	.long	0x48
	.byte	0xc
	.uleb128 0xe
	.long	.LASF33
	.byte	0x8
	.byte	0x3f
	.long	0x48
	.byte	0x10
	.uleb128 0xe
	.long	.LASF34
	.byte	0x8
	.byte	0x45
	.long	0x1f5
	.byte	0x14
	.uleb128 0xe
	.long	.LASF35
	.byte	0x8
	.byte	0x4a
	.long	0x205
	.byte	0x44
	.uleb128 0xe
	.long	.LASF36
	.byte	0x8
	.byte	0x50
	.long	0x21b
	.byte	0x74
	.uleb128 0xe
	.long	.LASF37
	.byte	0x8
	.byte	0x55
	.long	0x41
	.byte	0x78
	.byte	0
	.uleb128 0xf
	.long	0xd3
	.long	0x1e5
	.uleb128 0x10
	.long	0xcc
	.byte	0x3
	.byte	0
	.uleb128 0xf
	.long	0x25
	.long	0x1f5
	.uleb128 0x10
	.long	0xcc
	.byte	0x3
	.byte	0
	.uleb128 0xf
	.long	0x41
	.long	0x205
	.uleb128 0x10
	.long	0xcc
	.byte	0xb
	.byte	0
	.uleb128 0xf
	.long	0x215
	.long	0x215
	.uleb128 0x10
	.long	0xcc
	.byte	0xb
	.byte	0
	.uleb128 0x11
	.byte	0x4
	.long	0x25
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.long	.LASF38
	.uleb128 0x4
	.long	.LASF39
	.byte	0x1
	.byte	0x19
	.long	0x22d
	.uleb128 0x11
	.byte	0x4
	.long	0x233
	.uleb128 0x12
	.long	0x242
	.long	0x242
	.uleb128 0x13
	.long	0x242
	.byte	0
	.uleb128 0x11
	.byte	0x4
	.long	0x15c
	.uleb128 0x4
	.long	.LASF40
	.byte	0x1
	.byte	0x1a
	.long	0x253
	.uleb128 0x11
	.byte	0x4
	.long	0x259
	.uleb128 0x14
	.long	0x264
	.uleb128 0x13
	.long	0x242
	.byte	0
	.uleb128 0xd
	.long	.LASF42
	.byte	0x8
	.byte	0x1
	.byte	0x1f
	.long	0x289
	.uleb128 0xe
	.long	.LASF43
	.byte	0x1
	.byte	0x21
	.long	0x222
	.byte	0
	.uleb128 0xe
	.long	.LASF44
	.byte	0x1
	.byte	0x22
	.long	0x248
	.byte	0x4
	.byte	0
	.uleb128 0x4
	.long	.LASF42
	.byte	0x1
	.byte	0x23
	.long	0x264
	.uleb128 0x15
	.long	.LASF45
	.byte	0x1
	.byte	0x2a
	.long	0x21b
	.long	.LFB21
	.long	.LFE21-.LFB21
	.uleb128 0x1
	.byte	0x9c
	.long	0x2c6
	.uleb128 0x16
	.long	.LBB4
	.long	.LBE4-.LBB4
	.uleb128 0x17
	.string	"res"
	.byte	0x1
	.byte	0x2e
	.long	0x8f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.uleb128 0x15
	.long	.LASF46
	.byte	0x1
	.byte	0x3b
	.long	0x21b
	.long	.LFB22
	.long	.LFE22-.LFB22
	.uleb128 0x1
	.byte	0x9c
	.long	0x2f8
	.uleb128 0x16
	.long	.LBB7
	.long	.LBE7-.LBB7
	.uleb128 0x17
	.string	"res"
	.byte	0x1
	.byte	0x3f
	.long	0x8f
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.uleb128 0x18
	.long	.LASF56
	.byte	0x1
	.byte	0x4a
	.long	0x9a
	.long	.LFB23
	.long	.LFE23-.LFB23
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x19
	.long	.LASF57
	.byte	0x1
	.byte	0x50
	.long	0x242
	.long	.LFB24
	.long	.LFE24-.LFB24
	.uleb128 0x1
	.byte	0x9c
	.long	0x34d
	.uleb128 0x1a
	.long	.LASF47
	.byte	0x1
	.byte	0x50
	.long	0x242
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x16
	.long	.LBB8
	.long	.LBE8-.LBB8
	.uleb128 0x17
	.string	"ret"
	.byte	0x1
	.byte	0x5b
	.long	0x242
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.byte	0
	.byte	0
	.uleb128 0x1b
	.long	.LASF58
	.byte	0x1
	.byte	0x64
	.long	.LFB25
	.long	.LFE25-.LFB25
	.uleb128 0x1
	.byte	0x9c
	.long	0x371
	.uleb128 0x1a
	.long	.LASF48
	.byte	0x1
	.byte	0x64
	.long	0x242
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.byte	0
	.uleb128 0x1c
	.long	.LASF49
	.byte	0x1
	.byte	0x25
	.long	0x289
	.uleb128 0x5
	.byte	0x3
	.long	_ZL5g_Ext
	.uleb128 0x1c
	.long	.LASF50
	.byte	0x1
	.byte	0x26
	.long	0x21b
	.uleb128 0x5
	.byte	0x3
	.long	_ZL8g_GotExt
	.uleb128 0x1c
	.long	.LASF51
	.byte	0x1
	.byte	0x27
	.long	0x21b
	.uleb128 0x5
	.byte	0x3
	.long	_ZL10g_TriedExt
	.uleb128 0x1c
	.long	.LASF52
	.byte	0x1
	.byte	0x28
	.long	0x21b
	.uleb128 0x5
	.byte	0x3
	.long	_ZL15g_TriedNoMsgExt
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x8
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x8
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF2:
	.string	"short unsigned int"
.LASF36:
	.string	"m_GenerateMips"
.LASF24:
	.string	"bad_typeid"
.LASF31:
	.string	"m_Width"
.LASF53:
	.ascii	"GNU C++ 4.8 -fpreprocessed -mstackrealign -msse3 -m"
	.string	"bionic -m32 -mtune=atom -march=i686 -g -O0 -funsigned-char -fno-strict-aliasing -fno-stack-protector -fno-short-enums -fshort-wchar -fmessage-length=0 -fasynchronous-unwind-tables -fPIC -fvisibility=hidden -fvisibility-inlines-hidden -fno-exceptions -frtti"
.LASF46:
	.string	"_extLoadNoMsg"
.LASF13:
	.string	"s3eBool"
.LASF38:
	.string	"bool"
.LASF52:
	.string	"g_TriedNoMsgExt"
.LASF55:
	.string	"/Users/xiaolilillytang/Desktop/AmazingMaze/build_amazingmaze_scons_x86"
.LASF40:
	.string	"PVRTexToolFree_t"
.LASF45:
	.string	"_extLoad"
.LASF41:
	.string	"PVRTexToolData"
.LASF33:
	.string	"m_MipMaps"
.LASF48:
	.string	"data"
.LASF15:
	.string	"s3eMessageType"
.LASF0:
	.string	"unsigned char"
.LASF26:
	.string	"_STL"
.LASF47:
	.string	"input"
.LASF49:
	.string	"g_Ext"
.LASF29:
	.string	"m_Channels"
.LASF7:
	.string	"long unsigned int"
.LASF51:
	.string	"g_TriedExt"
.LASF27:
	.string	"__std_alias"
.LASF39:
	.string	"PVRTexToolConvert_t"
.LASF37:
	.string	"m_GLESFormat"
.LASF22:
	.string	"bad_exception"
.LASF3:
	.string	"short int"
.LASF14:
	.string	"wchar_t"
.LASF25:
	.string	"bad_cast"
.LASF32:
	.string	"m_Height"
.LASF28:
	.string	"stlport"
.LASF4:
	.string	"unsigned int"
.LASF21:
	.string	"exception"
.LASF17:
	.string	"S3E_MESSAGE_CONTINUE_STOP"
.LASF5:
	.string	"long long unsigned int"
.LASF42:
	.string	"PVRTexToolFuncs"
.LASF57:
	.string	"PVRTexToolConvert"
.LASF10:
	.string	"S3E_RESULT_ERROR"
.LASF56:
	.string	"PVRTexToolAvailable"
.LASF58:
	.string	"PVRTexToolFree"
.LASF19:
	.string	"sizetype"
.LASF6:
	.string	"long long int"
.LASF9:
	.string	"S3E_RESULT_SUCCESS"
.LASF20:
	.string	"char"
.LASF50:
	.string	"g_GotExt"
.LASF44:
	.string	"m_PVRTexToolFree"
.LASF18:
	.string	"S3E_MESSAGE_CONTINUE_STOP_IGNORE"
.LASF43:
	.string	"m_PVRTexToolConvert"
.LASF11:
	.string	"uint8"
.LASF23:
	.string	"type_info"
.LASF8:
	.string	"long int"
.LASF30:
	.string	"m_ChannelSizes"
.LASF35:
	.string	"m_Data"
.LASF34:
	.string	"m_Sizes"
.LASF1:
	.string	"signed char"
.LASF12:
	.string	"s3eResult"
.LASF54:
	.string	"/Applications/Marmalade.app/Contents/extensions/PVRTexTool/interface/PVRTexTool_interface.cpp"
.LASF16:
	.string	"S3E_MESSAGE_CONTINUE"
	.ident	"GCC: (GNU) 4.8"
	.section	.note.GNU-stack,"",@progbits
