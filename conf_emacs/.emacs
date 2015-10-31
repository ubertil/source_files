(setq emacs-lisp-dir "~/.emacs.d/"
      my-elmode-dir (concat emacs-lisp-dir "elmodes/"))
(setq load-path
      (append load-path (list my-elmode-dir)))

(add-to-list 'load-path "~/.emacs.d/")

(load "std.el")
(load "std_comment.el")
(if (file-exists-p "~/.myemacs")
    (load-file "~/.myemacs"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;; Start package.el with emacs
(require 'package)

;; Add MELPA to repository list
(add-to-list 'package-archives '("melpa" . "http://melpa.org/packages/") t)

;;Initialize package
(package-initialize)

;; Install auto-complete module
(require 'auto-complete)
(ac-config-default)

;; Install yasnippet
(require 'yasnippet)
(yas-global-mode 1)

;; Install Flycheck
(add-hook 'after-init-hook #'global-flycheck-mode)

;; Ajout de la gestion souris
(require 'mouse)
(xterm-mouse-mode t)
(global-set-key [mouse-4] (lambda ()
			    (interactive)
			    (scroll-down 1)))
(global-set-key [mouse-5] (lambda ()
			    (interactive)
			     (scroll-up 1)))
(defun track-mouse (e))
(setq mouse-sel-mode)

;; Suppresion des espaces en fin de ligne à l'enregistrement
(add-hook'before-save-hook'whitespace-cleanup)

;; Enlever le message
(setq inhibit-startup-message t)

;; Afficher les espaces inutiles
(setq-default show-trailing-whitespace t)

;; Afficher la parenthèse correspondante
(show-paren-mode)

;; Affiche le numéro de ligne et de colonne
(column-number-mode t)
(line-number-mode t)

;; MAX 80 colonnes
(setq-default fill-column 80)

;; Compter le nombre de lignes
(global-set-key [f4]'count-lines-region)

;; Affiche l'heure
(display-time-mode t)

;; Bold line
(global-hl-line-mode t)
(custom-set-faces
 '(highlight ((t (:weight bold)))))

;; Surbrillance de la region
(setq transient-mark-mode t)

;; Show tabs and too long lines
(custom-set-faces
 '(my-tab-face ((((class color)) (:foreground "black" :weight bold :underline t))) t)
 '(my-trailing-space-face ((((class color)) (:background "gray10"))) t)
 '(my-loong-line-face ((((class color)) (:background "yellow"))) t))

(defun cc-mode-add-keywords (mode)
  (font-lock-add-keywords
   mode
   '(
     ("\t+" (0 'my-tab-face append))
     ("^.\\{81\\}\\(.+\\)$" (1 'my-loong-line-face append)))))

(cc-mode-add-keywords 'c-mode)
(cc-mode-add-keywords 'php-mode)
(cc-mode-add-keywords 'sh-mode)
(cc-mode-add-keywords 'python-mode)
(cc-mode-add-keywords 'perl-mode)
(cc-mode-add-keywords 'c++-mode)
