LIBCORE = ConvolutionCore
LIBIMPLEMENTATION = MultichannelConvolution
LIBTEST = ConvolutionTest

.PHONY: all
all:
	$(MAKE) -C $(LIBCORE)
	$(MAKE) -C $(LIBIMPLEMENTATION)
	$(MAKE) -C $(LIBTEST)
	
.PHONY: clean
clean:

	$(MAKE) $@ -C $(LIBCORE)
	$(MAKE) $@ -C $(LIBIMPLEMENTATION)
	$(MAKE) $@ -C $(LIBTEST)
