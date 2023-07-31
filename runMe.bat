@echo off
cmd /k "git status  & pause & git add . & git status  & pause . & git commit -m \"notes\" & git status  & pause & git push origin main & pause"