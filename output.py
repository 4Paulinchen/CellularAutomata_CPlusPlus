import numpy as np
import matplotlib.pyplot as plt
fname = 'output.txt'
final =np.loadtxt(fname)
#final= np.reshape(final, (n+1,n))
plt.matshow(final,cmap="Greys",interpolation="bilinear")
plt.show()