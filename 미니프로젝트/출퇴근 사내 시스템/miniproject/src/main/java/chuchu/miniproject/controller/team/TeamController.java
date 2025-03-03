package chuchu.miniproject.controller.team;

import chuchu.miniproject.dto.user.request.RequestSaveTeam;
import chuchu.miniproject.dto.user.response.ResponseGetTeam;
import chuchu.miniproject.service.team.TeamService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequiredArgsConstructor
@RequestMapping("/api")
public class TeamController {


    private final TeamService teamService;

    @PostMapping("/team")
    public void saveTeam(@RequestBody RequestSaveTeam requestSaveTeam) {
        teamService.saveTeam(requestSaveTeam);
    }
    @GetMapping("/team")
    public List<ResponseGetTeam> getTeams() {
        return teamService.getTeams();
    }
}
