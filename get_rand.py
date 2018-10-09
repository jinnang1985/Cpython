import sys
import os 
dirpath = os.getcwd()
sys.path.insert(0, dirpath)

def get_rand():

  print "this is to run python"
  import numpy as np
  from scipy.linalg import cholesky
  corr_mat= np.array([[1.0, 0.6, 0.3],
                    [0.6, 1.0, 0.5],
                    [0.3, 0.5, 1.0]])
  upper_chol = cholesky(corr_mat)

  print upper_chol

  rnd = np.random.normal(0.0, 1.0, size=(10**2, 3))
# Finally, compute the inner product of upper_chol and rnd
  ans = np.dot(rnd, upper_chol)

  from scipy.stats import pearsonr
  corr_0_1 , _ = pearsonr(ans[:,0], ans[:,1])
  corr_0_2 , _ = pearsonr(ans[:,0], ans[:,2])
  corr_1_2 , _ = pearsonr(ans[:,1], ans[:,2])
  corr_0_0 , _ = pearsonr(ans[:,0], ans[:,0])
  print corr_0_1, corr_0_2, corr_1_2, corr_0_0

  return ans[:, 0]
